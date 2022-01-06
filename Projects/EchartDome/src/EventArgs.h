#ifndef EVENTARGS_H
#define EVENTARGS_H

#include <QObject>

class QJsonObject;

class EventArgs : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString content MEMBER m_content)
	Q_PROPERTY(int x MEMBER m_offset_x)
	Q_PROPERTY(int y MEMBER m_offset_y)

public slots:
	void slot_mouse_click(int x, int y);
	void slot_mouse_move(int x, int y);

signals:
	void sign_draw_rect(const QJsonObject& jsonData);

private:
	int m_offset_x;
	int m_offset_y;
	QString m_content;
};

#endif //EVENTARGS_H