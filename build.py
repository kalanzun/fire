import os
import subprocess


def run(arguments, env=None):
    subprocess.check_call(arguments, env=env)


def build_osx(env):
    env["PATH"] = "/usr/local/opt/qt/bin:" + env["PATH"]

    run(["qmake", "fire.pro"], env=env)
    run(["make"], env=env)

    tag = env["TRAVIS_TAG"]

    os.mkdir("build")
    run(["cp", "-r", "fire.app", "build/"])
    run(["macdeployqt", "build/fire.app"], env=env)

    run(
        [
            "hdiutil",
            "create",
            "-volname",
            "fire-" + tag,
            "-srcFolder",
            "build",
            "-ov",
            "-format",
            "UDZO",
            "Fire-" + tag + "-mac.dmg",
        ]
    )


def build_linux(env):
    run(["qmake", "fire.pro"])
    run(["make"])

    tag = env["TRAVIS_TAG"]

    run(
        [
            "wget",
            "-c",
            "-nv",
            "https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage",
        ]
    )
    run(["chmod", "a+x", "linuxdeployqt-continuous-x86_64.AppImage"])

    os.makedirs("build/usr/share/applications")
    run(["cp", "linux/fire.desktop", "build/usr/share/applications/"])

    os.makedirs("build/usr/share/icons/hicolor/scaleable/")
    run(["cp", "icons/fire.svg", "build/usr/share/icons/hicolor/scaleable/"])

    os.makedirs("build/usr/bin")
    run(["cp", "fire", "build/usr/bin/"])

    # linuxdeployqt uses VERSION environment variable for the filename
    env["VERSION"] = tag + "-linux"
    run(
        [
            "./linuxdeployqt-continuous-x86_64.AppImage",
            "build/usr/share/applications/fire.desktop",
            "-appimage",
        ],
        env=env,
    )


def main():
    env = dict(os.environ)

    if "TRAVIS_OS_NAME" in env:
        os_name = os.environ["TRAVIS_OS_NAME"]
    elif "APPVEYOR" in env:
        os_name = "windows"
    else:
        raise ValueError("Unknown CI service")

    if os_name == "linux":
        build_linux(env)
    elif os_name == "osx":
        build_osx(env)
    # elif os_name == "windows":
    #     build_windows(env)
    else:
        raise ValueError("Unknown operating system")


if __name__ == "__main__":
    main()
