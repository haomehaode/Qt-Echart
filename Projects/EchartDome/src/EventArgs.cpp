#include "EventArgs.h"
#include <QJsonObject>

void EventArgs::slot_mouse_click(int x, int y)
{
	QJsonObject json;
	json.insert("x", x);
	json.insert("y", y);
	json.insert("width", 100);
	json.insert("height", 50);
	emit sign_draw_rect(json);
}

void EventArgs::slot_mouse_move(int x, int y)
{

}
