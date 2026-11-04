#include "zhujiemian.h"
#include "ui_zhujiemian.h"
#include "mainwindow.h"
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
#include <QDateTime>
#include <QSqlRecord>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QMessageBox>

Zhujiemian::Zhujiemian(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zhujiemian)
{
    ui->setupUi(this);
    // 加载员工数据

    // 初始化订单和货物数据
    loadOrdersData();
    loadGoodsData();

    // 设置五张QRC路径的图片
    setFiveQrcImages();

    loadEmployeeImages(); // 加载员工图片

    // 连接信号与槽
    connect(ui->tableWidget_2, &QTableWidget::itemSelectionChanged, this, &Zhujiemian::on_tableWidget_2_itemSelectionChanged);
    connect(ui->listWidget_2, &QListWidget::itemEntered, this, &Zhujiemian::on_listWidget_2_itemEntered);

    // 隐藏垂直表头（序号）
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_3->verticalHeader()->setVisible(false);

    // 隐藏垂直表头（序号）
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_3->verticalHeader()->setVisible(false);
    // 连接信号与槽
    connect(ui->tableWidget_2, &QTableWidget::itemSelectionChanged, this, &Zhujiemian::on_tableWidget_2_itemSelectionChanged);
    // 初始化左边标签
    leftLabel = ui->label_31;
    leftLabel->setAlignment(Qt::AlignCenter); // 图片居中
    // 声明并获取原 label_32
    QLabel *originalLabel = ui->label_32;
    QWidget *originalParent = originalLabel->parentWidget(); // 正确获取父控件
    QRect labelRect = originalLabel->geometry();

    // 创建 RightArea 并设置父控件和位置
    rightArea = new RightArea(originalParent);
    rightArea->setGeometry(labelRect);
    rightArea->setObjectName("label_32");

    // 移除原 label_32
    delete originalLabel;

    // 设置初始图片
    rightArea->setPixmap(QPixmap(":/new/prefix1/19.png"));
    rightArea->setScaledContents(true);

    // 确保以下代码存在且 rightArea 已初始化
    connect(rightArea, &RightArea::imageChanged, this, &Zhujiemian::updateLeftImage);

    // 设置 label_29 的图片
    QPixmap pixmap6(":/new/prefix1/17.png"); // 替换为你的图片路径
    pixmap6 = pixmap6.scaled(ui->label_29->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_29->setPixmap(pixmap6);
    ui->label_29->setStyleSheet("background: transparent; border: none;");
    ui->label_29->setScaledContents(true);
    ui->label_29->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_29->setAlignment(Qt::AlignCenter);

    // 设置 label_30 的图片
    QPixmap pixmap7(":/new/prefix1/18.png"); // 替换为你的图片路径
    pixmap7 = pixmap7.scaled(ui->label_30->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_30->setPixmap(pixmap7);
    ui->label_30->setStyleSheet("background: transparent; border: none;");
    ui->label_30->setScaledContents(true);
    ui->label_30->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_30->setAlignment(Qt::AlignCenter);
    ui->pushButton_14->setIcon(QIcon(":/new/prefix1/13.png")); // 替换为你的图片路径
    ui->pushButton_14->setIconSize(QSize(30, 30)); // 设置图标大小
    ui->pushButton_14->setStyleSheet("QPushButton { background: transparent; border: none; }");

    // 设置 pushButton_10 的样式
    ui->pushButton_10->setIcon(QIcon(":/new/prefix1/15.png")); // 替换为你的图片路径
    ui->pushButton_10->setIconSize(QSize(30, 30)); // 设置图标大小
    ui->pushButton_10->setStyleSheet("QPushButton { background: transparent; border: none; }");

    // 设置 pushButton_11 的样式
    ui->pushButton_11->setIcon(QIcon(":/new/prefix1/16.png")); // 替换为你的图片路径
    ui->pushButton_11->setIconSize(QSize(30, 30)); // 设置图标大小
    ui->pushButton_11->setStyleSheet("QPushButton { background: transparent; border: none; }");

    // 设置刷新按钮
    ui->pushButton_12->setIcon(QIcon(":/new/prefix1/5.png"));
    ui->pushButton_12->setIconSize(QSize(24, 24));
    ui->pushButton_12->setStyleSheet("QPushButton { background: transparent; border: none; }");

    // 连接刷新按钮的点击事件
    connect(ui->pushButton_12, &QPushButton::clicked, this, &Zhujiemian::loadEvents);

    // 初始化事件列表
    loadEvents();
}

bool Zhujiemian::connectDB() {
    // 检查默认连接是否已存在且打开
    if (QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        QSqlDatabase db = QSqlDatabase::database(QSqlDatabase::defaultConnection);
        if (db.isOpen()) return true;
    }
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

void Zhujiemian::loadEvents() {
    if (!connectDB()) {
        return;
    }

    // 清空 listWidget
    ui->listWidget->clear();

    // 查询事件数据
    QSqlQuery query("SELECT EventType, EventDetail, Progress FROM warehouseevents ORDER BY RAND() LIMIT 5");
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        return;
    }

    // 添加事件项
    while (query.next()) {
        QString eventType = query.value(0).toString();
        QString eventDetail = query.value(1).toString();
        QString progress = query.value(2).toString();

        // 创建自定义事件项
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);

        // 创建图标标签
        QLabel *iconLabel = new QLabel();
        QPixmap pixmap;
        if (eventType == "完成") {
            pixmap = QPixmap(":/new/prefix1/6.png");
        } else if (eventType == "进行中") {
            pixmap = QPixmap(":/new/prefix1/7.png");
        } else if (eventType == "突发") {
            pixmap = QPixmap(":/new/prefix1/14.png");
        } else {
            pixmap = QPixmap(":/new/prefix1/14.png");
        }
        pixmap = pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        iconLabel->setPixmap(pixmap);
        iconLabel->setFixedSize(30, 30); // 设置固定大小
        layout->addWidget(iconLabel);

        // 创建EventType标签
        QLabel *eventTypeLabel = new QLabel(eventType);
        eventTypeLabel->setStyleSheet("color: #333333; font-size: 14px;");
        layout->addWidget(eventTypeLabel);

        // 创建EventDetail标签
        QLabel *eventDetailLabel = new QLabel(eventDetail);
        eventDetailLabel->setStyleSheet("color: #333333; font-size: 14px;");
        layout->addWidget(eventDetailLabel);

        // 创建Progress标签
        QLabel *progressLabel = new QLabel(progress);
        progressLabel->setStyleSheet("color: #333333; font-size: 14px;");
        layout->addWidget(progressLabel);

        // 设置布局间距
        layout->setSpacing(5); // 缩小标签之间的间距

        // 设置自定义widget的布局
        widget->setLayout(layout);

        // 设置item的大小提示
        item->setSizeHint(widget->sizeHint());

        // 将自定义widget设置到item中
        ui->listWidget->setItemWidget(item, widget);
    }

    loadEmployeeData();
    // 在构造函数中添加
    // 移除窗口边框、最小化和关闭按钮
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    // 在构造函数中添加密码框回显模式
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    ui->lineEdit_7->setEchoMode(QLineEdit::Password);

    inittreeWidget();

    // 设置样式表
    ui->treeWidget->setStyleSheet(R"(
    QTreeWidget {
        background-color: #555555; /* 更浅的灰色背景 */
        color: white; /* 字体颜色为白色 */
        border: 1px solid #666666; /* 边框颜色 */
        min-width: 250px; /* 增加宽度 */
        font-size: 14px; /* 增加字体大小 */
        outline: none; /* 去掉虚线选择框 */
    }
    QTreeWidget::item {
        background-color: #555555; /* 项的背景颜色 */
        color: white; /* 项的字体颜色 */
        padding: 8px; /* 增加内边距 */
        border-bottom: 1px solid #666666; /* 项的下边框 */
    }
    QTreeWidget::item:selected {
        background-color: #3498db; /* 选中项的背景颜色 */
        color: white; /* 选中项的字体颜色 */
    }
    QTreeWidget::branch {
        background-color: #555555; /* 展开键背景色 */
        color: white; /* 展开键颜色 */
    }
    QTreeWidget::branch:open {
        image: url(:/images/arrow_down.png); /* 展开图标 */
    }
    QTreeWidget::branch:closed {
        image: url(:/images/arrow_right.png); /* 折叠图标 */
    }
    QTreeWidget::header {
        background-color: #555555; /* 表头背景色 */
        color: white; /* 表头字体颜色 */
    }
    )");
    // 初始化表格属性
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels({"姓名", "年龄", "工号", "电话", "邮箱", "职责", "备注"});
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->resizeColumnsToContents(); // 自动调整列宽

    // 连接信号与槽
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &Zhujiemian::on_tableWidget_itemSelectionChanged);
    connect(ui->pushButton_9, &QPushButton::clicked,
            this, &Zhujiemian::on_pushButton_9_clicked);

    // 初始化时间标签
    timeLabel = new QLabel(this);
    updateTime(); // 设置初始时间
    timeLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0); color: white;");
    timeLabel->setGeometry(width() - 160, 10, 150, 30);

    // 创建定时器并连接其信号到槽函数
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Zhujiemian::updateTime);
    timer->start(1000); // 每秒更新一次

    // 设置按钮样式表
    ui->pushButton_9->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    // 设置 widget 的背景颜色为淡蓝色
    QWidget *widget = ui->widget;
    widget->setStyleSheet("background-color: #5D8AA8;"); // 淡蓝色背景

    // 设置 label 的字体颜色为白色
    QLabel *label = ui->label;
    label->setStyleSheet("QLabel { color: white; }"); // 字体改为白色

    // 获取 page_9 的指针
    QWidget *page9 = ui->page_9;

    // 获取 widget_2 的指针
    QWidget *widget2 = ui->widget_2;

    // 获取四个 frame 的指针
    QFrame *frame = ui->frame;
    QFrame *frame_2 = ui->frame_2;
    QFrame *frame_3 = ui->frame_3;
    QFrame *frame_4 = ui->frame_4;

    // 设置 frame 的样式
    frame->setStyleSheet("QFrame { background-color: white; border: 1px solid #e0e0e0; border-radius: 5px; }");
    frame_2->setStyleSheet("QFrame { background-color: white; border: 1px solid #e0e0e0; border-radius: 5px; }");
    frame_3->setStyleSheet("QFrame { background-color: white; border: 1px solid #e0e0e0; border-radius: 5px; }");
    frame_4->setStyleSheet("QFrame { background-color: white; border: 1px solid #e0e0e0; border-radius: 5px; }");

    // 获取图标标签的指针
    QLabel *label_12 = ui->label_12; // 图标
    QLabel *label_15 = ui->label_15; // 图标
    QLabel *label_18 = ui->label_18; // 图标
    QLabel *label_21 = ui->label_21; // 图标

    // 获取标题标签的指针
    QLabel *label_13 = ui->label_13; // 收藏
    QLabel *label_16 = ui->label_16; // 仓库剩余
    QLabel *label_19 = ui->label_19; // 人员总数
    QLabel *label_22 = ui->label_22; // 货物总数

    // 获取数值标签的指针
    QLabel *label_14 = ui->label_14; // 301
    QLabel *label_17 = ui->label_17; // 25°C
    QLabel *label_20 = ui->label_20; // 52%
    QLabel *label_23 = ui->label_23; // 12,109

    // 设置图标路径（在代码中用 // 标出来）
    label_12->setPixmap(QPixmap(":/new/prefix1/1.png")); // 替换为你的图标路径
    label_15->setPixmap(QPixmap(":/new/prefix1/2.png")); // 替换为你的图标路径
    label_18->setPixmap(QPixmap(":/new/prefix1/4.png")); // 替换为你的图标路径
    label_21->setPixmap(QPixmap(":/new/prefix1/3.png")); // 替换为你的图标路径

    // 去掉 QLabel 的边框
    label_12->setStyleSheet("QLabel { border: none; }");
    label_15->setStyleSheet("QLabel { border: none; }");
    label_18->setStyleSheet("QLabel { border: none; }");
    label_21->setStyleSheet("QLabel { border: none; }");

    // 设置标题样式（合并边框和字体样式）
    label_13->setStyleSheet("QLabel { border: none; color: #333333; font-size: 14px; }");
    label_16->setStyleSheet("QLabel { border: none; color: #333333; font-size: 14px; }");
    label_19->setStyleSheet("QLabel { border: none; color: #333333; font-size: 14px; }");
    label_22->setStyleSheet("QLabel { border: none; color: #333333; font-size: 14px; }");

    // 设置数值样式（合并边框和字体样式）
    label_14->setStyleSheet("QLabel { border: none; color: #333333; font-size: 18px; font-weight: bold; }");
    label_17->setStyleSheet("QLabel { border: none; color: #333333; font-size: 18px; font-weight: bold; }");
    label_20->setStyleSheet("QLabel { border: none; color: #333333; font-size: 18px; font-weight: bold; }");
    label_23->setStyleSheet("QLabel { border: none; color: #333333; font-size: 18px; font-weight: bold; }");

    // 设置标题内容
    label_13->setText("温度");
    label_16->setText("仓库剩余");
    label_19->setText("人员总数");
    label_22->setText("货物总数");

    // 设置数值内容
    label_14->setText("25°C");
    label_17->setText("52%");
    label_20->setText("12");
    label_23->setText("109");

    // 设置图标显示模式
    label_12->setScaledContents(true);
    label_15->setScaledContents(true);
    label_18->setScaledContents(true);
    label_21->setScaledContents(true);

    // ========== 设置 frame_5 到 frame_7 的样式 ==========
    QFrame *frame_5 = ui->frame_5;
    QFrame *frame_6 = ui->frame_6;
    QFrame *frame_7 = ui->frame_7;

    // 应用与原有框架相同的样式
    frame_5->setStyleSheet("QFrame { background-color: white; border: 1px solid #e0e0e0; border-radius: 5px; }");
    frame_6->setStyleSheet("QFrame { background-color: white; border: 1px solid #e0e0e0; border-radius: 5px; }");
    frame_7->setStyleSheet("QFrame { background-color: white; border: 1px solid #e0e0e0; border-radius: 5px; }");

    // ========== 设置 frame_5 内部标签 ==========
    // 获取 frame_5 内的标签指针
    QLabel *label_33 = ui->label_33; // 图标
    QLabel *label_34 = ui->label_34; // 标题
    QLabel *label_35 = ui->label_35; // 数值

    // 设置图标
    label_33->setPixmap(QPixmap(":/new/prefix1/24.png")); // 替换为实际图标路径
    label_33->setStyleSheet("QLabel { border: none; }");
    label_33->setScaledContents(true);

    // 设置标题
    label_34->setText("在卸货物");
    label_34->setStyleSheet("QLabel { border: none; color: #333333; font-size: 14px; }");

    // 设置数值
    label_35->setText("10吨");
    label_35->setStyleSheet("QLabel { border: none; color: #333333; font-size: 18px; font-weight: bold; }");

    // ========== 设置 frame_6 内部标签 ==========
    QLabel *label_36 = ui->label_36;
    QLabel *label_37 = ui->label_37;
    QLabel *label_38 = ui->label_38;

    label_36->setPixmap(QPixmap(":/new/prefix1/25.png")); // 替换路径
    label_36->setStyleSheet("QLabel { border: none; }");
    label_36->setScaledContents(true);

    label_37->setText("空闲月台");
    label_37->setStyleSheet("QLabel { border: none; color: #333333; font-size: 14px; }");

    label_38->setText("23");
    label_38->setStyleSheet("QLabel { border: none; color: #333333; font-size: 18px; font-weight: bold; }");

    // ========== 设置 frame_7 内部标签 ==========
    QLabel *label_39 = ui->label_39;
    QLabel *label_40 = ui->label_40;
    QLabel *label_41 = ui->label_41;

    label_39->setPixmap(QPixmap(":/new/prefix1/3.png")); // 替换路径
    label_39->setStyleSheet("QLabel { border: none; }");
    label_39->setScaledContents(true);

    label_40->setText("货物总量");
    label_40->setStyleSheet("QLabel { border: none; color: #333333; font-size: 14px; }");

    label_41->setText("107吨");
    label_41->setStyleSheet("QLabel { border: none; color: #333333; font-size: 18px; font-weight: bold; }");
}

Zhujiemian::~Zhujiemian()
{
    delete ui;
}

enum InitType {
    Login_Modify, Login_Delete,
    Staff_Info, Staff_Attendance,
    Warehouse_Status, Warehouse_Info,
    Logistics_Order, Logistics_Goods,
    Messaging_Send
};

void Zhujiemian::inittreeWidget()
{
    QTreeWidget *treeWidget = ui->treeWidget;
    treeWidget->clear(); // 清空原有内容

    // 隐藏表头
    treeWidget->header()->setVisible(false);

    // ========== 1. 登录管理模块 ==========
    QTreeWidgetItem *loginItem = new QTreeWidgetItem(treeWidget, {"登录管理"});
    QTreeWidgetItem *modifyAccount = new QTreeWidgetItem(loginItem, {"修改账户"});
    modifyAccount->setData(0, Qt::UserRole, Login_Modify);
    QTreeWidgetItem *deleteAccount = new QTreeWidgetItem(loginItem, {"删除账户"});
    deleteAccount->setData(0, Qt::UserRole, Login_Delete);

    // ========== 2. 人员管理模块 ==========
    QTreeWidgetItem *staffItem = new QTreeWidgetItem(treeWidget, {"人员管理"});
    QTreeWidgetItem *staffInfo = new QTreeWidgetItem(staffItem, {"员工信息管理"});
    staffInfo->setData(0, Qt::UserRole, Staff_Info);
    QTreeWidgetItem *attendance = new QTreeWidgetItem(staffItem, {"出勤记录"});
    attendance->setData(0, Qt::UserRole, Staff_Attendance);

    // ========== 3. 仓库管理模块 ==========
    QTreeWidgetItem *warehouseItem = new QTreeWidgetItem(treeWidget, {"仓库管理"});
    QTreeWidgetItem *warehouseStatus = new QTreeWidgetItem(warehouseItem, {"仓库区域状态"});
    warehouseStatus->setData(0, Qt::UserRole, Warehouse_Status);
    QTreeWidgetItem *warehouseInfo = new QTreeWidgetItem(warehouseItem, {"仓库信息"});
    warehouseInfo->setData(0, Qt::UserRole, Warehouse_Info);

    // ========== 4. 物流管理模块 ==========
    QTreeWidgetItem *logisticsItem = new QTreeWidgetItem(treeWidget, {"物流管理"});
    QTreeWidgetItem *orderManage = new QTreeWidgetItem(logisticsItem, {"订单管理"});
    orderManage->setData(0, Qt::UserRole, Logistics_Order);
    QTreeWidgetItem *goodsDetail = new QTreeWidgetItem(logisticsItem, {"货物详细"});
    goodsDetail->setData(0, Qt::UserRole, Logistics_Goods);

    // ========== 5. 信息收发模块 ==========
    QTreeWidgetItem *messagingItem = new QTreeWidgetItem(treeWidget, {"信息收发"});
    QTreeWidgetItem *msgSend = new QTreeWidgetItem(messagingItem, {"信息发送"});
    msgSend->setData(0, Qt::UserRole, Messaging_Send);

    // 设置树形控件属性
    treeWidget->expandAll();
    treeWidget->setIndentation(15);

    // 连接信号与槽（修改后的版本）
    connect(treeWidget, &QTreeWidget::itemClicked, [this](QTreeWidgetItem *item, int column){
        if(item->childCount() > 0) return; // 忽略父节点点击

        QVariant pageType = item->data(0, Qt::UserRole);
        if(pageType.isValid()) {
            cutPage(static_cast<InitType>(pageType.toInt()));
        }
    });
}

void Zhujiemian::cutPage(InitType type)
{
    switch(type) {
    case Login_Modify:
        ui->stackedWidget->setCurrentWidget(ui->page);    // 页面0：修改账户
        break;
    case Login_Delete:
        ui->stackedWidget->setCurrentWidget(ui->page_1);  // 页面1：删除账户
        break;
    case Staff_Info:
        ui->stackedWidget->setCurrentWidget(ui->page_2);  // 页面2：员工信息
        break;
    case Staff_Attendance:
        ui->stackedWidget->setCurrentWidget(ui->page_3);  // 页面3：出勤记录
        break;
    case Warehouse_Status:
        ui->stackedWidget->setCurrentWidget(ui->page_4);  // 页面4：仓库状态
        break;
    case Warehouse_Info:
        ui->stackedWidget->setCurrentWidget(ui->page_5);  // 页面5：仓库信息
        break;
    case Logistics_Order:
        ui->stackedWidget->setCurrentWidget(ui->page_6);  // 页面6：订单管理
        break;
    case Logistics_Goods:
        ui->stackedWidget->setCurrentWidget(ui->page_7);  // 页面7：货物详细
        break;
    case Messaging_Send:
        ui->stackedWidget->setCurrentWidget(ui->page_8);  // 页面8：信息发送
        break;
    default:
        qWarning() << "Unknown page type:" << type;
        break;
    }
}

void Zhujiemian::updateTime()
{
    // 获取当前时间
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    // 更新时间标签的文本
    timeLabel->setText(currentTime);
}

void Zhujiemian::on_tableWidget_itemSelectionChanged() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        showImageForRow(row);
    }
}


void Zhujiemian::on_pushButton_clicked()
{
    // 获取输入信息
    QString username = ui->lineEdit->text().trimmed();
    QString oldPassword = ui->lineEdit_2->text().trimmed();
    QString newPassword = ui->lineEdit_3->text().trimmed();

    // 输入验证
    if(username.isEmpty() || oldPassword.isEmpty() || newPassword.isEmpty()){
        QMessageBox::warning(this, "警告", "所有字段必须填写！");
        return;
    }

    if(oldPassword == newPassword){
        QMessageBox::warning(this, "警告", "新密码不能与旧密码相同！");
        return;
    }

    if(!connectDB()){
        return;
    }

    // 验证账号存在性
    QSqlQuery checkUser;
    checkUser.prepare("SELECT UserID, Password FROM Users WHERE Username = :username");
    checkUser.bindValue(":username", username);

    if(!checkUser.exec()){
        QMessageBox::critical(this, "错误", "数据库查询失败：" + checkUser.lastError().text());
        return;
    }

    if(!checkUser.next()){
        QMessageBox::warning(this, "警告", "账号不存在！");
        return;
    }

    // 验证旧密码
    QString storedHash = checkUser.value("Password").toString();
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(oldPassword.toUtf8());
    QString inputHash = hash.result().toHex();

    if(inputHash != storedHash){
        QMessageBox::warning(this, "警告", "旧密码错误！");
        return;
    }

    // 更新密码
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Users SET Password = SHA2(:newPassword, 256) WHERE Username = :username");
    updateQuery.bindValue(":newPassword", newPassword);
    updateQuery.bindValue(":username", username);

    if(updateQuery.exec()){
        QMessageBox::information(this, "成功", "密码修改成功！");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
    }else{
        QMessageBox::critical(this, "错误", "更新失败：" + updateQuery.lastError().text());
    }
}

void Zhujiemian::on_pushButton_2_clicked()
{
    // 关闭当前窗口并显示登录窗口
    this->close();
    MainWindow *loginWindow = new MainWindow();
    loginWindow->show();
}
void Zhujiemian::on_pushButton_3_clicked()
{
    // 第一步：获取输入信息
    QString targetAccount = ui->lineEdit_4->text().trimmed();
    QString targetPassword = ui->lineEdit_5->text().trimmed();
    QString operatorName = ui->lineEdit_6->text().trimmed();
    QString operatorPassword = ui->lineEdit_7->text().trimmed();

    // 输入验证
    if(targetAccount.isEmpty() || targetPassword.isEmpty() ||
        operatorName.isEmpty() || operatorPassword.isEmpty())
    {
        QMessageBox::warning(this, "警告", "所有字段必须填写！");
        return;
    }

    // 第二步：验证操作者权限
    if(operatorName != "YFK") {
        QMessageBox::warning(this, "权限不足", "只有管理员YFK可执行此操作！");
        return;
    }

    if(!connectDB()) return;

    // 验证YFK密码
    QSqlQuery checkOperator;
    checkOperator.prepare("SELECT Password FROM Users WHERE FullName = 'YFK'");
    if(!checkOperator.exec() || !checkOperator.next()) {
        QMessageBox::critical(this, "错误", "管理员验证失败：" + checkOperator.lastError().text());
        return;
    }

    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(operatorPassword.toUtf8());
    QString storedHash = checkOperator.value("Password").toString();
    if(hash.result().toHex() != storedHash) {
        QMessageBox::warning(this, "验证失败", "操作者密码错误！");
        return;
    }

    // 第三步：弹出确认对话框
    QMessageBox::StandardButton confirmDelete;
    confirmDelete = QMessageBox::question(
        this,
        "确认删除",
        QString("确定要删除用户【%1】的账号吗？").arg(targetAccount),
        QMessageBox::Yes | QMessageBox::No
        );

    if(confirmDelete == QMessageBox::No) {
        this->close();
        MainWindow *mainWin = new MainWindow();
        mainWin->show();
        return;
    }

    // 第四步：执行删除操作
    QSqlQuery deleteUser;
    deleteUser.prepare("DELETE FROM Users WHERE Username = :username AND Password = SHA2(:password, 256)");
    deleteUser.bindValue(":username", targetAccount);
    deleteUser.bindValue(":password", targetPassword);

    if(deleteUser.exec()) {
        if(deleteUser.numRowsAffected() > 0) {
            QMessageBox::information(
                this,
                "删除成功",
                QString("用户【%1】已成功删除！").arg(targetAccount)
                );
        } else {
            QMessageBox::warning(
                this,
                "删除失败",
                "账号或密码不匹配，或用户不存在！"
                );
        }
    } else {
        QMessageBox::critical(
            this,
            "数据库错误",
            "删除操作失败：" + deleteUser.lastError().text()
            );
    }

    // 返回主界面
    this->close();
    Zhujiemian *zhujiemian = new Zhujiemian();
    zhujiemian->show();
}

void Zhujiemian::on_pushButton_4_clicked()
{
    // 直接返回主界面
    this->close();
    MainWindow *mainWin = new MainWindow();
    mainWin->show();
}

void Zhujiemian::loadEmployeeData() {
    if (!connectDB()) return;

    QSqlQuery query("SELECT FullName, Age, EmployeeNumber, PhoneNumber, Email, CurrentResponsibility, Remarks FROM Employee");
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        return;
    }
    // 调整列数为7列（原为8列）
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels({"姓名", "年龄", "工号", "电话", "邮箱", "职责", "备注"});
    ui->tableWidget->setRowCount(0);
    imageCache.clear(); // 清空图片缓存

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        for (int col = 0; col < 7; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget->setItem(row, col, item);
        }

        // 加载图片数据
        QString empNumber = query.value(2).toString(); // EmployeeNumber 是第3列（索引2）
        QSqlQuery imgQuery;
        imgQuery.prepare("SELECT ImageData FROM Employee WHERE EmployeeNumber = ?");
        imgQuery.addBindValue(empNumber);
        if (imgQuery.exec() && imgQuery.next()) {
            imageCache[row] = imgQuery.value(0).toByteArray();
        }
        row++;
    }

    // 设置列宽模式为 Stretch，使列宽自动调整以填满可用空间
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Zhujiemian::showImageForRow(int row) {
    if (row < 0 || row >= ui->tableWidget->rowCount()) return;

    // 通过工号查询图片
    QString empNumber = ui->tableWidget->item(row, 2)->text();
    QSqlQuery imgQuery;
    imgQuery.prepare("SELECT ImageData FROM Employee WHERE EmployeeNumber = ?");
    imgQuery.addBindValue(empNumber);

    if (imgQuery.exec() && imgQuery.next()) {
        QByteArray imageData = imgQuery.value(0).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(imageData);
        ui->label_11->setPixmap(pixmap.scaled(ui->label_11->size(), Qt::KeepAspectRatio));
    } else {
        ui->label_11->clear();
    }
}

void Zhujiemian::on_pushButton_9_clicked() { // 新的按钮点击事件
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "警告", "请先选择要修改的行！");
        return;
    }

    // 弹出文件选择对话框
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "选择图片",
        "",
        "图片文件 (*.png *.jpg *.jpeg)"
        );

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray imageData = file.readAll();
            imageCache[row] = imageData; // 更新图片缓存
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            ui->label_11->setPixmap(
                pixmap.scaled(ui->label_11->size(), Qt::KeepAspectRatio)
                );
            file.close();
        } else {
            QMessageBox::critical(this, "错误", "无法读取图片文件！");
        }
    }
}

void Zhujiemian::on_pushButton_5_clicked() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "警告", "请先选择要修改的行！");
        return;
    }

    // 获取工号（第3列，索引2）
    QString empNumber = ui->tableWidget->item(row, 2)->text();
    if (empNumber.isEmpty()) {
        QMessageBox::warning(this, "错误", "工号不能为空！");
        return;
    }

    // 获取其他字段数据
    QString fullName = ui->tableWidget->item(row, 0)->text();
    int age = ui->tableWidget->item(row, 1)->text().toInt();
    QString phone = ui->tableWidget->item(row, 3)->text();
    QString email = ui->tableWidget->item(row, 4)->text();
    QString responsibility = ui->tableWidget->item(row, 5)->text();
    QString remarks = ui->tableWidget->item(row, 6)->text();
    QByteArray imageData = imageCache[row];

    QSqlQuery query;
    query.prepare("UPDATE Employee SET FullName=?, Age=?, PhoneNumber=?, Email=?, ImageData=?, CurrentResponsibility=?, Remarks=? WHERE EmployeeNumber=?");
    query.addBindValue(fullName);
    query.addBindValue(age);
    query.addBindValue(phone);
    query.addBindValue(email);
    query.addBindValue(imageData, QSql::In | QSql::Binary);
    query.addBindValue(responsibility);
    query.addBindValue(remarks);
    query.addBindValue(empNumber); // 使用工号作为 WHERE 条件

    if (query.exec()) {
        QMessageBox::information(this, "成功", "修改已保存！");
        loadEmployeeData();
    } else {
        QMessageBox::critical(this, "错误", "保存失败：" + query.lastError().text());
    }
}

void Zhujiemian::on_pushButton_6_clicked() {
    if (currentUser != "YFK") {
        QMessageBox::warning(this, "权限不足", "只有管理员YFK可执行此操作！");
        return;
    }

    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "警告", "请先选择要删除的行！");
        return;
    }

    // 获取工号（第3列，索引2）
    QString empNumber = ui->tableWidget->item(row, 2)->text();
    QString fullName = ui->tableWidget->item(row, 0)->text();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "确认删除", QString("确定要删除【%1】的信息吗？").arg(fullName),
        QMessageBox::Yes | QMessageBox::No
        );

    if (confirm == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM Employee WHERE EmployeeNumber=?");
        query.addBindValue(empNumber); // 使用工号作为删除条件

        if (query.exec()) {
            QMessageBox::information(this, "成功", "删除成功！");
            loadEmployeeData();
        } else {
            QMessageBox::critical(this, "错误", "删除失败：" + query.lastError().text());
        }
    }
}

void Zhujiemian::on_pushButton_7_clicked() {
    // 检查必填字段
    if (ui->tableWidget->item(0, 0)->text().isEmpty() ||  // 姓名（第1列，索引0）
        ui->tableWidget->item(0, 2)->text().isEmpty()) {  // 工号（第3列，索引2）
        QMessageBox::warning(this, "警告", "姓名和工号不能为空！");
        return;
    }

    // 获取输入数据
    QString fullName = ui->tableWidget->item(0, 0)->text();
    int age = ui->tableWidget->item(0, 1)->text().toInt();
    QString empNumber = ui->tableWidget->item(0, 2)->text();
    QString phone = ui->tableWidget->item(0, 3)->text();
    QString email = ui->tableWidget->item(0, 4)->text();
    QString responsibility = ui->tableWidget->item(0, 5)->text();
    QString remarks = ui->tableWidget->item(0, 6)->text();
    QByteArray imageData = imageCache.value(0);

    QSqlQuery query;
    query.prepare("INSERT INTO Employee (FullName, Age, EmployeeNumber, PhoneNumber, Email, ImageData, CurrentResponsibility, Remarks) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(fullName);
    query.addBindValue(age);
    query.addBindValue(empNumber);
    query.addBindValue(phone);
    query.addBindValue(email);
    query.addBindValue(imageData, QSql::In | QSql::Binary);
    query.addBindValue(responsibility);
    query.addBindValue(remarks);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "新增员工成功！");
        loadEmployeeData();
    } else {
        QMessageBox::critical(this, "错误", "新增失败：" + query.lastError().text());
    }
}

void Zhujiemian::on_pushButton_8_clicked(){
    loadEmployeeData();
}

void Zhujiemian::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragging = true;
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Zhujiemian::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void Zhujiemian::mouseReleaseEvent(QMouseEvent *event)
{
    dragging = false;
}

// RightArea 的构造函数：
RightArea::RightArea(QWidget *parent) : QLabel(parent) {
    setMouseTracking(true); // 启用鼠标跟踪
}
void RightArea::mouseMoveEvent(QMouseEvent *event) {
    QPoint pos = event->pos();
    determineRegionAndUpdateImage(pos);
}

void RightArea::determineRegionAndUpdateImage(const QPoint &pos) {
    int width = this->width();
    int height = this->height();
    QString imagePath;

    // 根据坐标判断区域（示例：四象限）
    if (pos.x() < width/2 && pos.y() < height/2) {
        imagePath = ":/new/prefix1/20.jpg"; // 左上区域
    } else if (pos.x() >= width/2 && pos.y() < height/2) {
        imagePath = ":/new/prefix1/21.jpg"; // 右上区域
    } else if (pos.x() < width/2 && pos.y() >= height/2) {
        imagePath = ":/new/prefix1/22.jpg"; // 左下区域
    } else {
        imagePath = ":/new/prefix1/23.jpg"; // 右下区域
    }
    emit imageChanged(imagePath);
}


void Zhujiemian::updateLeftImage(const QString &path) {
    QPixmap pixmap(path);
    leftLabel->setPixmap(pixmap.scaled(
        leftLabel->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        ));
}

void Zhujiemian::loadOrdersData() {
    if (!connectDB()) return;

    // 清空 tableWidget_2
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(4);
    ui->tableWidget_2->setHorizontalHeaderLabels({"订单编号", "订单出发", "订单终点", "物流公司"});
    ui->tableWidget_2->setRowCount(0);

    // 查询订单数据
    QSqlQuery query("SELECT OrderID, Departure, Destination, LogisticsCompany FROM Orders");

    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableWidget_2->insertRow(row);
        for (int col = 0; col < 4; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_2->setItem(row, col, item);
        }
        row++;
    }

    // 设置列宽模式为 Stretch，使列宽自动调整以填满可用空间
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Zhujiemian::loadGoodsData() {
    if (!connectDB()) return;

    // 清空 tableWidget_3
    ui->tableWidget_3->clear();
    ui->tableWidget_3->setColumnCount(5);
    ui->tableWidget_3->setHorizontalHeaderLabels({"货物名称", "货物数量", "货物属性", "订单编号", "货物图片"});
    ui->tableWidget_3->setRowCount(0);

    // 查询货物数据
    QSqlQuery query("SELECT GoodsName, GoodsQuantity, GoodsAttributes, OrderID, GoodsImage FROM Goods");

    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableWidget_3->insertRow(row);
        for (int col = 0; col < 4; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_3->setItem(row, col, item);
        }

        // 处理图片数据
        QByteArray imageData = query.value(4).toByteArray();
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            QLabel *imageLabel = new QLabel();
            pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            imageLabel->setPixmap(pixmap);
            imageLabel->setAlignment(Qt::AlignCenter);
            ui->tableWidget_3->setCellWidget(row, 4, imageLabel);
        }

        row++;
    }

    // 设置列宽模式为 Stretch，使列宽自动调整以填满可用空间
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Zhujiemian::on_tableWidget_2_itemSelectionChanged() {
    int row = ui->tableWidget_2->currentRow();
    if (row >= 0) {
        QString orderID = ui->tableWidget_2->item(row, 0)->text();

        // 清空 tableWidget_3
        ui->tableWidget_3->clear();
        ui->tableWidget_3->setColumnCount(5);
        ui->tableWidget_3->setHorizontalHeaderLabels({"货物名称", "货物数量", "货物属性", "订单编号", "货物图片"});
        ui->tableWidget_3->setRowCount(0);

        // 查询该订单相关的货物数据
        QSqlQuery query;
        query.prepare("SELECT GoodsName, GoodsQuantity, GoodsAttributes, OrderID, GoodsImage FROM Goods WHERE OrderID = ?");
        query.addBindValue(orderID);

        if (!query.exec()) {
            QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
            return;
        }

        int goodsRow = 0;
        while (query.next()) {
            ui->tableWidget_3->insertRow(goodsRow);
            for (int col = 0; col < 4; col++) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tableWidget_3->setItem(goodsRow, col, item);
            }

            // 处理图片数据
            QByteArray imageData = query.value(4).toByteArray();
            if (!imageData.isEmpty()) {
                QPixmap pixmap;
                pixmap.loadFromData(imageData);
                QLabel *imageLabel = new QLabel();
                pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                imageLabel->setPixmap(pixmap);
                imageLabel->setAlignment(Qt::AlignCenter);
                ui->tableWidget_3->setCellWidget(goodsRow, 4, imageLabel);
            }

            goodsRow++;
        }

        // 设置列宽模式为 Stretch
        ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

void Zhujiemian::loadEmployeeImages() {
    if (!connectDB()) return;

    ui->listWidget_2->clear();

    // 获取 listWidget_2 的可用宽度（减去滚动条和边距）
    int listWidth = ui->listWidget_2->viewport()->width() - 20; // 留出边距
    if (listWidth <= 0) listWidth = 200; // 默认宽度

    QSqlQuery query("SELECT FullName, ImageData FROM Employee");
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString fullName = query.value(0).toString();
        QByteArray imageData = query.value(1).toByteArray();

        if (imageData.isEmpty()) {
            qDebug() << "员工" << fullName << "的图片数据为空！";
            continue;
        }

        QPixmap pixmap;
        if (!pixmap.loadFromData(imageData)) {
            qDebug() << "员工" << fullName << "的图片加载失败！";
            continue;
        }

        // 动态计算缩放尺寸：横向填满，高度按比例自适应
        int targetWidth = listWidth;
        int targetHeight = pixmap.height() * targetWidth / pixmap.width();

        // 缩放图片
        pixmap = pixmap.scaled(targetWidth, targetHeight, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

        // 创建列表项
        QListWidgetItem *item = new QListWidgetItem();
        item->setData(Qt::UserRole, fullName);
        item->setSizeHint(QSize(targetWidth, targetHeight + 10)); // 增加间距

        // 创建显示图片的标签
        QLabel *label = new QLabel();
        label->setPixmap(pixmap);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("background: transparent; border: none; padding: 5px;");

        ui->listWidget_2->addItem(item);
        ui->listWidget_2->setItemWidget(item, label);
    }

    // 设置列表属性
    ui->listWidget_2->setViewMode(QListView::ListMode);
    ui->listWidget_2->setResizeMode(QListView::Adjust);
    ui->listWidget_2->setMovement(QListView::Static);
    ui->listWidget_2->setSpacing(5);
    ui->listWidget_2->setMouseTracking(true);

    // 设置样式：横向填满，禁用水平滚动条
    ui->listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget_2->setMouseTracking(true);
    ui->listWidget_2->setStyleSheet(
        "QListWidget::item:hover { background-color: #e0e0e0; }"
        "QListWidget::item:!hover { background-color: transparent; }"
        );
}

void Zhujiemian::on_listWidget_2_itemEntered(QListWidgetItem *item) {
    if (item) {
        // 从 UserRole 中获取用户名
        QString fullName = item->data(Qt::UserRole).toString();

        // 更新 label_43 的文本
        ui->label_43->setText(fullName);
        ui->label_43->setStyleSheet("color: black;"); // 确保文本可见

        // 可选：高亮当前悬停项
        if (currentHoveredItem) {
            currentHoveredItem->setBackground(Qt::transparent);
        }
        item->setBackground(QColor("#e0e0e0"));
        currentHoveredItem = item;
    }
}

void Zhujiemian::setFiveQrcImages() {
    // 清空标签
    ui->label_44->clear();
    ui->label_45->clear();
    ui->label_46->clear();
    ui->label_47->clear();
    ui->label_48->clear();

    // 加载五张图片
    QString imagePaths[5] = {
        ":/new/prefix1/26.png",
        ":/new/prefix1/27.png",
        ":/new/prefix1/28.png",
        ":/new/prefix1/29.png",
        ":/new/prefix1/30.png",
    };

    QLabel *labels[5] = {ui->label_44, ui->label_45, ui->label_46, ui->label_47, ui->label_48};

    for (int i = 0; i < 5; i++) {
        QPixmap pixmap(imagePaths[i]);
        if (!pixmap.isNull()) {
            // 获取标签的大小
            int width = labels[i]->width();
            int height = labels[i]->height();

            // 缩放图片以适应标签大小
            pixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            // 设置图片到标签
            labels[i]->setPixmap(pixmap);
            labels[i]->setStyleSheet("background: transparent; border: none;");
            labels[i]->setAlignment(Qt::AlignCenter);
        }
    }
}
