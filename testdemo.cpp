#include "testdemo.h"
#include "Register.h"
#include "core.h"
#include <QMessageBox>

testdemo::testdemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->setWindowIcon(QIcon(":/testdemo/image/shulogo.png"));//设定图标
	this->setWindowTitle("登录");//设置窗口标题为<登录>
	//ui.pw->setEchoMode(QLineEdit::Password);//将密码输入框设为密码模式，不显示输入字符，已在ui界面设置
	ui.username->setFocus();
	ui.loginin->setDefault(true);
	ui.loginin->setShortcut(Qt::Key_Enter);
}

testdemo::~testdemo()
{}

void testdemo::PushLoginClicked() {
	if (ui.username->text() == "admin" && ui.pw->text() == "123456") {//登录判断，后期对接接口，函数输入账号密码字符串，返回bool值
		this->hide();//切换新页面
		core *c = new core(ui.username->text(),nullptr,this);
		c->show();
		ui.pw->clear();
	}
	else {
		QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码输入错误！"), QMessageBox::Ok);
		ui.pw->clear();
		ui.username->setFocus();
	}


}

void testdemo::PushRegisterClicked() {
	Register *r = new Register;
	r->show();
}