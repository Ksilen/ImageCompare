/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *folderButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelForSlider;
    QSlider *horizontalSlider;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *findButton;
    QPushButton *addFolderButton;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelNotAgain;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QListWidget *widgetForIcons;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *notSelectButton;
    QPushButton *deleteSelectedButton;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QTableWidget *listOfImages;
    QVBoxLayout *verticalLayout_2;
    QLabel *screenImage;
    QLabel *imagePropertiesLabel;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *notSelectButton2;
    QPushButton *deleteSelectedButton2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(600, 411);
        verticalLayout_7 = new QVBoxLayout(Widget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_8 = new QHBoxLayout(tab);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 27));

        horizontalLayout_2->addWidget(lineEdit);

        folderButton = new QPushButton(tab);
        folderButton->setObjectName(QStringLiteral("folderButton"));
        folderButton->setMinimumSize(QSize(0, 27));
        folderButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    border-style: outset;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout_2->addWidget(folderButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(17, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer = new QSpacerItem(318, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelForSlider = new QLabel(tab);
        labelForSlider->setObjectName(QStringLiteral("labelForSlider"));
        labelForSlider->setMinimumSize(QSize(30, 0));
        labelForSlider->setMaximumSize(QSize(16777215, 16777215));
        labelForSlider->setBaseSize(QSize(30, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(true);
        labelForSlider->setFont(font1);
        labelForSlider->setFrameShape(QFrame::NoFrame);

        horizontalLayout_3->addWidget(labelForSlider);

        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QLatin1String("QSlider {\n"
"    color: #333;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
""));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(100);
        horizontalSlider->setSliderPosition(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider->setTickInterval(5);

        horizontalLayout_3->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(17, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        findButton = new QPushButton(tab);
        findButton->setObjectName(QStringLiteral("findButton"));
        findButton->setFont(font);
        findButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    border-style: outset;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout->addWidget(findButton);

        addFolderButton = new QPushButton(tab);
        addFolderButton->setObjectName(QStringLiteral("addFolderButton"));
        addFolderButton->setFont(font);
        addFolderButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    border-style: outset;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout->addWidget(addFolderButton);

        horizontalSpacer_8 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        labelNotAgain = new QLabel(tab);
        labelNotAgain->setObjectName(QStringLiteral("labelNotAgain"));
        labelNotAgain->setMinimumSize(QSize(150, 25));
        QFont font2;
        font2.setPointSize(10);
        labelNotAgain->setFont(font2);

        verticalLayout_5->addWidget(labelNotAgain);

        verticalSpacer_3 = new QSpacerItem(553, 87, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_8->addLayout(verticalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widgetForIcons = new QListWidget(tab_2);
        widgetForIcons->setObjectName(QStringLiteral("widgetForIcons"));
        widgetForIcons->setFrameShape(QFrame::Box);
        widgetForIcons->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        widgetForIcons->setEditTriggers(QAbstractItemView::NoEditTriggers);
        widgetForIcons->setProperty("showDropIndicator", QVariant(false));
        widgetForIcons->setDragDropMode(QAbstractItemView::DragDrop);
        widgetForIcons->setSelectionMode(QAbstractItemView::NoSelection);
        widgetForIcons->setIconSize(QSize(100, 100));
        widgetForIcons->setTextElideMode(Qt::ElideNone);
        widgetForIcons->setResizeMode(QListView::Adjust);
        widgetForIcons->setGridSize(QSize(130, 100));
        widgetForIcons->setViewMode(QListView::IconMode);
        widgetForIcons->setUniformItemSizes(false);

        verticalLayout_6->addWidget(widgetForIcons);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        notSelectButton = new QPushButton(tab_2);
        notSelectButton->setObjectName(QStringLiteral("notSelectButton"));
        notSelectButton->setMinimumSize(QSize(110, 41));
        notSelectButton->setFont(font);
        notSelectButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    border-style: outset;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout_5->addWidget(notSelectButton);

        deleteSelectedButton = new QPushButton(tab_2);
        deleteSelectedButton->setObjectName(QStringLiteral("deleteSelectedButton"));
        deleteSelectedButton->setMinimumSize(QSize(170, 41));
        deleteSelectedButton->setFont(font);
        deleteSelectedButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    border-style: outset;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout_5->addWidget(deleteSelectedButton);


        verticalLayout_6->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_8 = new QVBoxLayout(tab_3);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        listOfImages = new QTableWidget(tab_3);
        listOfImages->setObjectName(QStringLiteral("listOfImages"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listOfImages->sizePolicy().hasHeightForWidth());
        listOfImages->setSizePolicy(sizePolicy);
        listOfImages->setMinimumSize(QSize(180, 297));
        listOfImages->setBaseSize(QSize(180, 297));
        listOfImages->setFont(font2);

        horizontalLayout_6->addWidget(listOfImages);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        screenImage = new QLabel(tab_3);
        screenImage->setObjectName(QStringLiteral("screenImage"));
        screenImage->setMinimumSize(QSize(355, 251));
        screenImage->setSizeIncrement(QSize(100, 100));
        screenImage->setBaseSize(QSize(355, 251));
        screenImage->setStyleSheet(QLatin1String("color: rgb(253, 255, 106);\n"
"background-color: rgb(58, 252, 255);\n"
"background-color: rgb(180, 180, 180);"));

        verticalLayout_2->addWidget(screenImage);

        imagePropertiesLabel = new QLabel(tab_3);
        imagePropertiesLabel->setObjectName(QStringLiteral("imagePropertiesLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imagePropertiesLabel->sizePolicy().hasHeightForWidth());
        imagePropertiesLabel->setSizePolicy(sizePolicy1);
        imagePropertiesLabel->setMinimumSize(QSize(331, 35));
        imagePropertiesLabel->setFont(font2);
        imagePropertiesLabel->setStyleSheet(QStringLiteral("background-color: rgb(197, 197, 197);"));

        verticalLayout_2->addWidget(imagePropertiesLabel);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        notSelectButton2 = new QPushButton(tab_3);
        notSelectButton2->setObjectName(QStringLiteral("notSelectButton2"));
        notSelectButton2->setMinimumSize(QSize(110, 41));
        notSelectButton2->setFont(font);
        notSelectButton2->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    border-style: outset;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout_7->addWidget(notSelectButton2);

        deleteSelectedButton2 = new QPushButton(tab_3);
        deleteSelectedButton2->setObjectName(QStringLiteral("deleteSelectedButton2"));
        deleteSelectedButton2->setMinimumSize(QSize(110, 41));
        deleteSelectedButton2->setFont(font);
        deleteSelectedButton2->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 5px;\n"
"    border-style: outset;\n"
"        background-color: rgb(208, 208, 201);\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout_7->addWidget(deleteSelectedButton2);


        verticalLayout_8->addLayout(horizontalLayout_7);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_7->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
#ifndef QT_NO_TOOLTIP
        folderButton->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\272\320\260\321\202\320\260\320\273\320\276\320\263 \320\277\320\276\320\270\321\201\320\272\320\260</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        folderButton->setText(QString());
        label->setText(QApplication::translate("Widget", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 :", 0));
        labelForSlider->setText(QApplication::translate("Widget", "100", 0));
        findButton->setText(QApplication::translate("Widget", "\320\235\320\260\320\271\321\202\320\270 \320\276\320\264\320\270\320\275\320\260\320\272\320\276\320\262\321\213\320\265", 0));
        addFolderButton->setText(QApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", 0));
        labelNotAgain->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\320\247\321\202\320\276 \320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214?", 0));
        notSelectButton->setText(QApplication::translate("Widget", "\320\241\320\275\321\217\321\202\321\214 \320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\217", 0));
        deleteSelectedButton->setText(QApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\320\230\320\272\320\276\320\275\320\272\320\270", 0));
        screenImage->setText(QString());
        imagePropertiesLabel->setText(QString());
        notSelectButton2->setText(QApplication::translate("Widget", "\320\241\320\275\321\217\321\202\321\214 \320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\217", 0));
        deleteSelectedButton2->setText(QApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "\320\232\320\260\321\200\321\202\320\270\320\275\320\272\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
