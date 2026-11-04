#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zhuce.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QTimer>
#include <QSqlQuery>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mainInterface(nullptr)
    , dragging(false)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    setWindowTitle("登录");
    // 移除窗口边框、最小化和关闭按钮
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 设置背景颜色
    this->setStyleSheet("background-color: #CCF8FF;"); // 您可以更改颜色代码来自定义背景颜色

    // 设置 label_2 显示企鹅图标并适应控件大小
    ui->label_2->setPixmap(QPixmap(":/new/prefix1/9_1741456044.png").scaled(ui->label_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->label_2->setMask(ui->label_2->pixmap().mask()); // 设置圆形遮罩
    ui->label_2->setStyleSheet("background: transparent;");

    // 设置 lineEdit 的 placeholderText
    ui->lineEdit->setPlaceholderText("输入账号");
    ui->lineEdit_2->setPlaceholderText("输入密码");

    // 设置 lineEdit 的样式，指定非常淡且非常细的边框，并使四个角变得圆润
    ui->lineEdit->setStyleSheet(
        "QLineEdit {"
        "border: 1px solid rgba(0, 0, 0, 0.1);"  // 使用RGBA定义一个非常淡的颜色，透明度为0.1
        "border-radius: 8px;"                    // 圆角半径设置为8px，可以根据需要调整
        "padding: 5px;"
        "background-color: #FFFFFF;"             // 背景颜色，可以根据实际情况调整
        "}"
        "QLineEdit:focus {"
        "border: 1px solid rgba(51, 153, 255, 0.8);"  // 当 QLineEdit 获取焦点时的边框颜色，稍微明显一点
        "border-radius: 8px;"                          // 保持相同的圆角半径
        "}"
        );
    ui->lineEdit_2->setStyleSheet(
        "QLineEdit {"
        "border: 1px solid rgba(0, 0, 0, 0.1);"
        "border-radius: 8px;"                            // 圆角半径设置为8px，可以根据需要调整
        "padding: 5px;"
        "background-color: #FFFFFF;"
        "}"
        "QLineEdit:focus {"
        "border: 1px solid rgba(51, 153, 255, 0.8);"
        "border-radius: 8px;"                            // 保持相同的圆角半径
        "}"
        );

    // 设置按钮样式
    ui->pushButton->setStyleSheet("QPushButton { background-color: #3399FF; color: white; border: none; border-radius: 5px; padding: 8px; }"
                                  "QPushButton:hover { background-color: #2288FF; }");
    ui->pushButton_2->setStyleSheet("QPushButton { background: transparent; color: #3399FF; border: none; }");
    ui->pushButton_3->setStyleSheet("QPushButton { background: transparent; color: #3399FF; border: none; }");
    ui->pushButton_4->setStyleSheet("QPushButton { background: transparent; border: none; }");
    ui->pushButton_5->setStyleSheet("QPushButton { background: transparent; border: none; }");

    // 设置 pushButton_4 和 pushButton_5 的图标
    ui->pushButton_4->setIcon(QIcon(":/new/prefix1/10.png"));
    ui->pushButton_5->setIcon(QIcon(":/new/prefix1/11.png"));


    // 设置按钮的圆角效果
    ui->pushButton->setStyleSheet("QPushButton { background-color: #3399FF; color: white; border: none; border-radius: 5px; padding: 8px; }"
                                  "QPushButton:hover { background-color: #2288FF; }");

    // 初始化数据库连接
    if (!connectDB()) {
        QMessageBox::critical(this, "错误", "数据库连接失败，程序即将退出");
        QTimer::singleShot(0, qApp, &QCoreApplication::quit);
    }

    // 绑定按钮点击事件
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);  // 登录按钮
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);  // 退出按钮
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);  // 注册按钮
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_pushButton_5_clicked);  // 关闭按钮
}

MainWindow::~MainWindow()
{
    delete ui;
    if (mainInterface) delete mainInterface;
}
// ------------------- 数据库连接 -------------------
bool MainWindow::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);                   // 修正端口为3306
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("200212177");

    if (!db.open()) {
        QMessageBox::critical(this, "错误", "数据库连接失败：" + db.lastError().text());
        return false;
    }
    return true;
}

// ------------------- 登录逻辑 -------------------
void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();  // 用户名输入框
    QString password = ui->lineEdit_2->text();  // 密码输入框

    // 1. 验证账号是否存在
    if (!validateAccount(username)) {
        QMessageBox::warning(this, "错误", "账号不存在");
        return;
    }

    // 2. 验证密码是否正确
    if (!validatePassword(username, password)) {
        QMessageBox::warning(this, "错误", "密码错误");
        return;
    }

    // 3. 获取用户姓名
    QString fullName = getFullName(username);

    // 4. 登录成功，跳转主界面
    QMessageBox::information(this, "欢迎", "欢迎 " + fullName);
    this->hide();  // 关闭登录对话框（QDialog::Accepted）
    Zhujiemian *mainInterface = new Zhujiemian();
    mainInterface->show();
}

// ------------------- 验证账号存在性 -------------------
bool MainWindow::validateAccount(const QString &username)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Users WHERE Username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

// ------------------- 验证密码 -------------------
bool MainWindow::validatePassword(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT Password FROM Users WHERE Username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        QString storedHash = query.value(0).toString();
        QString inputHash = QCryptographicHash::hash(
                                password.toUtf8(), QCryptographicHash::Sha256
                                ).toHex();
        return storedHash == inputHash;
    }
    return false;
}

// ------------------- 获取用户姓名 -------------------
QString MainWindow::getFullName(const QString &username)
{
    QSqlQuery query;
    query.prepare("SELECT FullName FROM Users WHERE Username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return "未知用户";  // 如果查询失败，返回默认值
}

// ------------------- 退出按钮 -------------------
void MainWindow::on_pushButton_2_clicked()
{
    this->close();  // 直接关闭窗口
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragging = true;
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    dragging = false;
}

void MainWindow::on_pushButton_5_clicked()
{
    this->close();  // 关闭窗口
}

void MainWindow::on_pushButton_3_clicked()
{
    // 创建注册窗口对象，并指定父对象为nullptr（避免被主窗口销毁）
    Zhuce *regWindow = new Zhuce(nullptr);  // 关键修改：父对象设为nullptr
    regWindow->setWindowModality(Qt::ApplicationModal);  // 设置为模态窗口
    regWindow->show();
    this->hide();  // 隐藏当前窗口
}
