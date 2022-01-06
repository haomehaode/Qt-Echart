#ifndef ECHARTDOME_H
#define ECHARTDOME_H

#include <QtWidgets/QMainWindow>
#include "ui_EchartDome.h"

class QWebChannel;
class EventArgs;

class EchartDome : public QMainWindow
{
    Q_OBJECT
public:
    EchartDome(QWidget *parent = Q_NULLPTR);

public slots:
	void slot_resize_echart();
	void slot_basic_scatter();
	void slot_large_scatter();
	void slot_scatter_nebula();
	void slot_area_simple();

private:
	void resizeEvent(QResizeEvent* event) override;

private:
	bool isLoaded = false;
	QWebChannel* webChannel = nullptr;
	EventArgs* webobj = nullptr;

private:
    Ui::EchartDomeClass ui;
};

#endif //ECHARTDOME_H