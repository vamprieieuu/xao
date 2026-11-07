#include "gui/MainWindow.h"

#include <QApplication>
#include <QFileInfo>
#include <QTimer>

#include <string>

// Entry point for the Qt GUI.
//
//   ascii_cam_gui [path]              open an image/video, else start the webcam
//   ascii_cam_gui --selftest-ms N     launch, run the event loop N ms, then quit
//                                     (a headless smoke test for CI)
int main(int argc, char** argv) {
    QApplication app(argc, argv);

    asciicam::gui::MainWindow window;

    int selftestMs = 0;
    QString openPath;
    QString shotPath;
    QString recPath;
    int recMs = 2000;
    for (int i = 1; i < argc; ++i) {
        const std::string a = argv[i];
        if (a == "--selftest-ms" && i + 1 < argc) {
            selftestMs = std::atoi(argv[++i]);
        } else if (a == "--shot" && i + 1 < argc) {
            shotPath = QString::fromStdString(argv[++i]);
        } else if (a == "--rec" && i + 1 < argc) {
            recPath = QString::fromStdString(argv[++i]);
        } else if (a == "--rec-ms" && i + 1 < argc) {
            recMs = std::atoi(argv[++i]);
        } else if (!a.empty() && a[0] != '-' && QFileInfo::exists(QString::fromStdString(a))) {
            openPath = QString::fromStdString(a);
        }
    }

    window.show();

    const bool headless = !shotPath.isEmpty() || !recPath.isEmpty() || selftestMs > 0;
    if (!openPath.isEmpty()) {
        window.openFile(openPath);
    } else if (!headless) {
        window.useWebcam(0);
    }

    // Headless snapshot: let a few frames flow, save a PNG, then quit.
    if (!shotPath.isEmpty()) {
        QTimer::singleShot(1000, &app, [&] {
            window.saveSnapshot(shotPath);
            app.quit();
        });
    } else if (!recPath.isEmpty()) {
        window.beginRecording(recPath);
        QTimer::singleShot(recMs, &app, [&] {
            window.endRecording();
            app.quit();
        });
    } else if (selftestMs > 0) {
        QTimer::singleShot(selftestMs, &app, &QApplication::quit);
    }
    return app.exec();
}
