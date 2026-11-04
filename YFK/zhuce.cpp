#include "zhuce.h"
#include "ui_zhuce.h"
#include "mainwindow.h"

Zhuce::Zhuce(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Zhuce)
{
    ui->setupUi(this);
    // 移除窗口边框、最小化和关闭按钮
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    setWindowTitle("注册");

    // 设置背景颜色
    this->setStyleSheet("background-color: #CCF8FF;");

    ui->label->setPixmap(QPixmap(":/new/prefix1/12.png").scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->label->setMask(ui->label->pixmap().mask()); // 设置圆形遮罩
    ui->label->setStyleSheet("background: transparent;");

    // 设置 lineEdit 的 placeholderText
    ui->lineEdit->setPlaceholderText("输入新账号");
    ui->lineEdit_2->setPlaceholderText("输入密码");
    ui->lineEdit_3->setPlaceholderText("确认密码");
    ui->lineEdit_4->setPlaceholderText("输入姓名");

    // 设置 lineEdit 的样式，指定非常淡且非常细的边框，并使四个角变得圆润
    ui->lineEdit->setStyleSheet(
        "QLineEdit {"
        "border: 1px solid rgba(0, 0, 0, 0.1);"
        "border-radius: 8px;"
        "padding: 5px;"
        "background-color: #FFFFFF;"
        "}"
        "QLineEdit:focus {"
        "border: 1px solid rgba(51, 153, 255, 0.8);"
        "border-radius: 8px;"
        "}"
        );
    ui->lineEdit_2->setStyleSheet(
        "QLineEdit {"
        "border: 1px solid rgba(0, 0, 0, 0.1);"
        "border-radius: 8px;"
        "padding: 5px;"
        "background-color: #FFFFFF;"
        "}"
        "QLineEdit:focus {"
        "border: 1px solid rgba(51, 153, 255, 0.8);"
        "border-radius: 8px;"
        "}"
        );
    ui->lineEdit_3->setStyleSheet(
        "QLineEdit {"
        "border: 1px solid rgba(0, 0, 0, 0.1);"
        "border-radius: 8px;"
        "padding: 5px;"
        "background-color: #FFFFFF;"
        "}"
        "QLineEdit:focus {"
        "border: 1px solid rgba(51, 153, 255, 0.8);"
        "border-radius: 8px;"
        "}"
        );
    ui->lineEdit_4->setStyleSheet(
        "QLineEdit {"
        "border: 1px solid rgba(0, 0, 0, 0.1);"
        "border-radius: 8px;"
        "padding: 5px;"
        "background-color: #FFFFFF;"
        "}"
        "QLineEdit:focus {"
        "border: 1px solid rgba(51, 153, 255, 0.8);"
        "border-radius: 8px;"
        "}"
        );

    // 设置按钮样式
    ui->pushButton->setStyleSheet("QPushButton { background-color: #3399FF; color: white; border: none; border-radius: 5px; padding: 8px; }"
                                  "QPushButton:hover { background-color: #2288FF; }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: #3399FF; color: white; border: none; border-radius: 5px; padding: 8px; }"
                                  "QPushButton:hover { background-color: #2288FF; }");
    ui->pushButton_3->setStyleSheet("QPushButton { background: transparent; color: #3399FF; border: none; }");

    // 设置按钮的圆角效果
    ui->pushButton->setStyleSheet("QPushButton { background-color: #3399FF; color: white; border: none; border-radius: 5px; padding: 8px; }"
                                  "QPushButton:hover { background-color: #2288FF; }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: #3399FF; color: white; border: none; border-radius: 5px; padding: 8px; }"
                                  "QPushButton:hover { background-color: #2288FF; }");
    ui->pushButton_3->setStyleSheet("QPushButton { background: transparent; color: #3399FF; border: none; }");

    // 设置 pushButton_3 的图标
    ui->pushButton_3->setIcon(QIcon(":/new/prefix1/11.png"));
}

Zhuce::~Zhuce()
{
    delete ui;
}

// ------------------- 数据库连接 -------------------
bool Zhuce::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("200212177");

    if (!db.open()) {
        QMessageBox::critical(this, "错误", "数据库连接失败：" + db.lastError().text());
        return false;
    }
    return true;
}

// ------------------- 确定按钮点击事件 -------------------
void Zhuce::on_pushButton_clicked()
{
    QString username = ui->lineEdit_4->text();  // 用户姓名
    QString account = ui->lineEdit->text();    // 账号
    QString password = ui->lineEdit_2->text(); // 密码
    QString confirmPassword = ui->lineEdit_3->text(); // 确认密码

    // 输入验证
    if (username.isEmpty() || account.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "错误", "所有字段均为必填项");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "错误", "两次输入的密码不一致");
        return;
    }

    if (!connectDB()) return;

    registerUser(username, account, password);
}

// ------------------- 取消按钮点击事件 -------------------
void Zhuce::on_pushButton_2_clicked()
{
    // 创建登录窗口对象，并显示
    MainWindow *loginWindow = new MainWindow();
    this->close();
    loginWindow->show();

}

// ------------------- 关闭按钮点击事件 -------------------
void Zhuce::on_pushButton_3_clicked()
{
    this->close();
}

// ------------------- 注册用户 -------------------
void Zhuce::registerUser(const QString &username, const QString &account, const QString &password)
{
    QString passwordHash = QCryptographicHash::hash(
                               password.toUtf8(), QCryptographicHash::Sha256
                               ).toHex();

    QSqlQuery query;
    query.prepare("INSERT INTO Users (Username, Password, FullName) VALUES (:username, :password, :fullname)");
    query.bindValue(":username", account);  // 账号存储在 Username 字段
    query.bindValue(":password", passwordHash);
    query.bindValue(":fullname", username);  // 用户姓名存储在 FullName 字段

    if (query.exec()) {
        QMessageBox::information(this, "成功", "注册成功");
        emit registrationSuccess();  // 发射信号
        this->close();
    } else {
        QMessageBox::critical(this, "错误", "注册失败：" + query.lastError().text());
    }
}
