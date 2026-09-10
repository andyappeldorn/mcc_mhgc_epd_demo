#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen0_pnlBase;
leLabelWidget* Screen0_lbl_y1;
leLabelWidget* Screen0_lbl_y2;
leLabelWidget* Screen0_lbl_y3;
leLabelWidget* Screen0_lbl_y4;
leLabelWidget* Screen0_lbl_y5;
leLabelWidget* Screen0_lbl_y6;
leLabelWidget* Screen0_lbl_y7;
leLabelWidget* Screen0_lbl_x1;
leLabelWidget* Screen0_lbl_x2;
leLabelWidget* Screen0_lbl_x3;
leLabelWidget* Screen0_lbl_x4;
leLabelWidget* Screen0_lbl_x5;
leLabelWidget* Screen0_lbl_yPos;
leLabelWidget* Screen0_lbl_xPos;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, LE_DEFAULT_SCREEN_WIDTH, LE_DEFAULT_SCREEN_HEIGHT);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_pnlBase = leWidget_New();
    Screen0_pnlBase->fn->setPosition(Screen0_pnlBase, 1, 0);
    Screen0_pnlBase->fn->setSize(Screen0_pnlBase, 240, 360);
    Screen0_pnlBase->fn->setScheme(Screen0_pnlBase, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_pnlBase);

    Screen0_lbl_y1 = leLabelWidget_New();
    Screen0_lbl_y1->fn->setPosition(Screen0_lbl_y1, 5, 5);
    Screen0_lbl_y1->fn->setSize(Screen0_lbl_y1, 70, 30);
    Screen0_lbl_y1->fn->setScheme(Screen0_lbl_y1, &WhiteScheme);
    Screen0_lbl_y1->fn->setString(Screen0_lbl_y1, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_y1);

    Screen0_lbl_y2 = leLabelWidget_New();
    Screen0_lbl_y2->fn->setPosition(Screen0_lbl_y2, 5, 40);
    Screen0_lbl_y2->fn->setSize(Screen0_lbl_y2, 70, 30);
    Screen0_lbl_y2->fn->setScheme(Screen0_lbl_y2, &WhiteScheme);
    Screen0_lbl_y2->fn->setString(Screen0_lbl_y2, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_y2);

    Screen0_lbl_y3 = leLabelWidget_New();
    Screen0_lbl_y3->fn->setPosition(Screen0_lbl_y3, 5, 75);
    Screen0_lbl_y3->fn->setSize(Screen0_lbl_y3, 70, 30);
    Screen0_lbl_y3->fn->setScheme(Screen0_lbl_y3, &WhiteScheme);
    Screen0_lbl_y3->fn->setString(Screen0_lbl_y3, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_y3);

    Screen0_lbl_y4 = leLabelWidget_New();
    Screen0_lbl_y4->fn->setPosition(Screen0_lbl_y4, 5, 110);
    Screen0_lbl_y4->fn->setSize(Screen0_lbl_y4, 70, 30);
    Screen0_lbl_y4->fn->setScheme(Screen0_lbl_y4, &WhiteScheme);
    Screen0_lbl_y4->fn->setString(Screen0_lbl_y4, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_y4);

    Screen0_lbl_y5 = leLabelWidget_New();
    Screen0_lbl_y5->fn->setPosition(Screen0_lbl_y5, 5, 145);
    Screen0_lbl_y5->fn->setSize(Screen0_lbl_y5, 70, 30);
    Screen0_lbl_y5->fn->setScheme(Screen0_lbl_y5, &WhiteScheme);
    Screen0_lbl_y5->fn->setString(Screen0_lbl_y5, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_y5);

    Screen0_lbl_y6 = leLabelWidget_New();
    Screen0_lbl_y6->fn->setPosition(Screen0_lbl_y6, 5, 180);
    Screen0_lbl_y6->fn->setSize(Screen0_lbl_y6, 70, 30);
    Screen0_lbl_y6->fn->setScheme(Screen0_lbl_y6, &WhiteScheme);
    Screen0_lbl_y6->fn->setString(Screen0_lbl_y6, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_y6);

    Screen0_lbl_y7 = leLabelWidget_New();
    Screen0_lbl_y7->fn->setPosition(Screen0_lbl_y7, 5, 215);
    Screen0_lbl_y7->fn->setSize(Screen0_lbl_y7, 70, 30);
    Screen0_lbl_y7->fn->setScheme(Screen0_lbl_y7, &WhiteScheme);
    Screen0_lbl_y7->fn->setString(Screen0_lbl_y7, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_y7);

    Screen0_lbl_x1 = leLabelWidget_New();
    Screen0_lbl_x1->fn->setPosition(Screen0_lbl_x1, 5, 280);
    Screen0_lbl_x1->fn->setSize(Screen0_lbl_x1, 70, 30);
    Screen0_lbl_x1->fn->setScheme(Screen0_lbl_x1, &WhiteScheme);
    Screen0_lbl_x1->fn->setString(Screen0_lbl_x1, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_x1);

    Screen0_lbl_x2 = leLabelWidget_New();
    Screen0_lbl_x2->fn->setPosition(Screen0_lbl_x2, 45, 310);
    Screen0_lbl_x2->fn->setSize(Screen0_lbl_x2, 70, 30);
    Screen0_lbl_x2->fn->setScheme(Screen0_lbl_x2, &WhiteScheme);
    Screen0_lbl_x2->fn->setString(Screen0_lbl_x2, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_x2);

    Screen0_lbl_x3 = leLabelWidget_New();
    Screen0_lbl_x3->fn->setPosition(Screen0_lbl_x3, 85, 280);
    Screen0_lbl_x3->fn->setSize(Screen0_lbl_x3, 70, 30);
    Screen0_lbl_x3->fn->setScheme(Screen0_lbl_x3, &WhiteScheme);
    Screen0_lbl_x3->fn->setString(Screen0_lbl_x3, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_x3);

    Screen0_lbl_x4 = leLabelWidget_New();
    Screen0_lbl_x4->fn->setPosition(Screen0_lbl_x4, 130, 310);
    Screen0_lbl_x4->fn->setSize(Screen0_lbl_x4, 70, 30);
    Screen0_lbl_x4->fn->setScheme(Screen0_lbl_x4, &WhiteScheme);
    Screen0_lbl_x4->fn->setString(Screen0_lbl_x4, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_x4);

    Screen0_lbl_x5 = leLabelWidget_New();
    Screen0_lbl_x5->fn->setPosition(Screen0_lbl_x5, 165, 280);
    Screen0_lbl_x5->fn->setSize(Screen0_lbl_x5, 70, 30);
    Screen0_lbl_x5->fn->setScheme(Screen0_lbl_x5, &WhiteScheme);
    Screen0_lbl_x5->fn->setString(Screen0_lbl_x5, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_x5);

    Screen0_lbl_yPos = leLabelWidget_New();
    Screen0_lbl_yPos->fn->setPosition(Screen0_lbl_yPos, 162, 207);
    Screen0_lbl_yPos->fn->setSize(Screen0_lbl_yPos, 70, 30);
    Screen0_lbl_yPos->fn->setScheme(Screen0_lbl_yPos, &WhiteScheme);
    Screen0_lbl_yPos->fn->setString(Screen0_lbl_yPos, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_yPos);

    Screen0_lbl_xPos = leLabelWidget_New();
    Screen0_lbl_xPos->fn->setPosition(Screen0_lbl_xPos, 119, 173);
    Screen0_lbl_xPos->fn->setSize(Screen0_lbl_xPos, 70, 30);
    Screen0_lbl_xPos->fn->setScheme(Screen0_lbl_xPos, &WhiteScheme);
    Screen0_lbl_xPos->fn->setString(Screen0_lbl_xPos, (leString*)&string_strNaN);
    root0->fn->addChild(root0, (leWidget*)Screen0_lbl_xPos);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_MONOCHROME);

    Screen0_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Screen0_OnUpdate(); // raise event
}

void screenHide_Screen0(void)
{
    Screen0_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_pnlBase = NULL;
    Screen0_lbl_y1 = NULL;
    Screen0_lbl_y2 = NULL;
    Screen0_lbl_y3 = NULL;
    Screen0_lbl_y4 = NULL;
    Screen0_lbl_y5 = NULL;
    Screen0_lbl_y6 = NULL;
    Screen0_lbl_y7 = NULL;
    Screen0_lbl_x1 = NULL;
    Screen0_lbl_x2 = NULL;
    Screen0_lbl_x3 = NULL;
    Screen0_lbl_x4 = NULL;
    Screen0_lbl_x5 = NULL;
    Screen0_lbl_yPos = NULL;
    Screen0_lbl_xPos = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen0(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

