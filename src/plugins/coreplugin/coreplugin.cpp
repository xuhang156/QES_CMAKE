#include "coreplugin.h"
#include <QMainWindow>
#include <QTimer>

namespace Core {
namespace Internal {

CorePlugin::CorePlugin()
{
}

CorePlugin::~CorePlugin()
{

}

bool CorePlugin::initialize(const QStringList &arguments, QString *errorMessage)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorMessage)
    m_mainWindow = new QMainWindow();
    qDebug() << "initialize Core Plugin";
    return true;
}

void CorePlugin::extensionsInitialized()
{
    qDebug() << "extensions initialized Core Plugin";
    QTimer::singleShot(0, this, [this]() {
        m_mainWindow->show();
    });
}

bool CorePlugin::delayedInitialize()
{
    qDebug() << "delayed initialize Core Plugin";

    return true;
}

} // namespace Internal
} // namespace Core
