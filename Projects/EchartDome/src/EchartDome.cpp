#include "EchartDome.h"
#include "EventArgs.h"
#include <QWebEngineView>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMouseEvent>
#include <QWebChannel>
#include <QMessageBox>

EchartDome::EchartDome(QWidget *parent)
    : QMainWindow(parent)
{
	QString str = qApp->applicationDirPath() + "/echart/index.html";
	ui.setupUi(this);
	setWindowState(Qt::WindowMaximized);

	webChannel = new QWebChannel;
	webobj = new EventArgs;
	webChannel->registerObject("webobj", webobj);
	ui.webEngineView->page()->setWebChannel(webChannel);

	ui.webEngineView->setContextMenuPolicy(Qt::NoContextMenu);
	ui.webEngineView->setUrl(QUrl(str));
	connect(ui.webEngineView, SIGNAL(loadFinished(bool)), this, SLOT(slot_resize_echart()));
}

void EchartDome::slot_resize_echart()
{
	isLoaded = true;
	QJsonObject sizeData;
	sizeData.insert("width", ui.webEngineView->width() - 20);
	sizeData.insert("height", ui.webEngineView->height() - 20);
	QString sizeStr = QJsonDocument(sizeData).toJson();
	QString js = QString("setSize(%1)").arg(sizeStr);
	ui.webEngineView->page()->runJavaScript(js);
}

void EchartDome::slot_basic_scatter()
{
	/*QString str = qApp->applicationDirPath() + "/echart/index.html";
	ui.webEngineView->setUrl(QUrl(str));*/
	QJsonArray data;
	for (int i = 0; i < 100; i++)
	{
		QJsonArray array;
		for (int j = 0; j < 2; j++)
		{
			array.append(qrand() % 1000000);
		}
		data.append(array);
	}
	QJsonObject seriesData;
	QJsonArray data1 = { 1, 3, 9, 27, 81, 247, 741, 2223, 6669 };
	seriesData.insert("array", data1);
	seriesData.insert("arr", data);

	QString sizeStr = QJsonDocument(seriesData).toJson();
	QString js = QString("setData(%1)").arg(sizeStr);
	ui.webEngineView->page()->runJavaScript(js);
}

void EchartDome::slot_large_scatter()
{
	QString str = qApp->applicationDirPath() + "/echart/scatter-large.html";
	ui.webEngineView->setUrl(QUrl(str));
}

void EchartDome::slot_scatter_nebula()
{
	QString str = qApp->applicationDirPath() + "/echart/scatter-nebula.html";
	ui.webEngineView->setUrl(QUrl(str));
}

void EchartDome::slot_area_simple()
{
	QString str = qApp->applicationDirPath() + "/echart/area-simple.html";
	ui.webEngineView->setUrl(QUrl(str));
}

void EchartDome::resizeEvent(QResizeEvent* event)
{
	if (isLoaded)
		slot_resize_echart();
}

