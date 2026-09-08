#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen0_pnlBase;
leImageWidget* Screen0_imgMchp;
leButtonWidget* Screen0_btnQuickstart;
leLabelWidget* Screen0_lblCounter;
leButtonWidget* Screen0_ButtonWidget_Up;
leButtonWidget* Screen0_ButtonWidget_Down;

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
    Screen0_pnlBase->fn->setPosition(Screen0_pnlBase, 0, 0);
    Screen0_pnlBase->fn->setSize(Screen0_pnlBase, 240, 360);
    Screen0_pnlBase->fn->setScheme(Screen0_pnlBase, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_pnlBase);

    Screen0_imgMchp = leImageWidget_New();
    Screen0_imgMchp->fn->setPosition(Screen0_imgMchp, 0, 0);
    Screen0_imgMchp->fn->setSize(Screen0_imgMchp, 240, 45);
    Screen0_imgMchp->fn->setBackgroundType(Screen0_imgMchp, LE_WIDGET_BACKGROUND_NONE);
    Screen0_imgMchp->fn->setBorderType(Screen0_imgMchp, LE_WIDGET_BORDER_NONE);
    Screen0_imgMchp->fn->setImage(Screen0_imgMchp, (leImage*)&imgMchp);
    root0->fn->addChild(root0, (leWidget*)Screen0_imgMchp);

    Screen0_btnQuickstart = leButtonWidget_New();
    Screen0_btnQuickstart->fn->setPosition(Screen0_btnQuickstart, 27, 257);
    Screen0_btnQuickstart->fn->setSize(Screen0_btnQuickstart, 200, 60);
    Screen0_btnQuickstart->fn->setScheme(Screen0_btnQuickstart, &WhiteScheme);
    Screen0_btnQuickstart->fn->setBackgroundType(Screen0_btnQuickstart, LE_WIDGET_BACKGROUND_NONE);
    Screen0_btnQuickstart->fn->setBorderType(Screen0_btnQuickstart, LE_WIDGET_BORDER_NONE);
    Screen0_btnQuickstart->fn->setToggleable(Screen0_btnQuickstart, LE_TRUE);
    Screen0_btnQuickstart->fn->setString(Screen0_btnQuickstart, (leString*)&string_strQuickstart);
    Screen0_btnQuickstart->fn->setPressedImage(Screen0_btnQuickstart, (leImage*)&btn2);
    Screen0_btnQuickstart->fn->setReleasedImage(Screen0_btnQuickstart, (leImage*)&btn);
    Screen0_btnQuickstart->fn->setImagePosition(Screen0_btnQuickstart, LE_RELATIVE_POSITION_BEHIND);
    root0->fn->addChild(root0, (leWidget*)Screen0_btnQuickstart);

    Screen0_lblCounter = leLabelWidget_New();
    Screen0_lblCounter->fn->setPosition(Screen0_lblCounter, 111, 86);
    Screen0_lblCounter->fn->setSize(Screen0_lblCounter, 130, 100);
    Screen0_lblCounter->fn->setBackgroundType(Screen0_lblCounter, LE_WIDGET_BACKGROUND_NONE);
    Screen0_lblCounter->fn->setHAlignment(Screen0_lblCounter, LE_HALIGN_CENTER);
    Screen0_lblCounter->fn->setString(Screen0_lblCounter, (leString*)&string_strCount);
    root0->fn->addChild(root0, (leWidget*)Screen0_lblCounter);

    Screen0_ButtonWidget_Up = leButtonWidget_New();
    Screen0_ButtonWidget_Up->fn->setPosition(Screen0_ButtonWidget_Up, 20, 74);
    Screen0_ButtonWidget_Up->fn->setSize(Screen0_ButtonWidget_Up, 80, 80);
    Screen0_ButtonWidget_Up->fn->setScheme(Screen0_ButtonWidget_Up, &WhiteScheme);
    Screen0_ButtonWidget_Up->fn->setBackgroundType(Screen0_ButtonWidget_Up, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Up->fn->setReleasedEventCallback(Screen0_ButtonWidget_Up, event_Screen0_ButtonWidget_Up_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen0_ButtonWidget_Up);

    Screen0_ButtonWidget_Down = leButtonWidget_New();
    Screen0_ButtonWidget_Down->fn->setPosition(Screen0_ButtonWidget_Down, 20, 166);
    Screen0_ButtonWidget_Down->fn->setSize(Screen0_ButtonWidget_Down, 80, 80);
    Screen0_ButtonWidget_Down->fn->setScheme(Screen0_ButtonWidget_Down, &WhiteScheme);
    Screen0_ButtonWidget_Down->fn->setBackgroundType(Screen0_ButtonWidget_Down, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Down->fn->setReleasedEventCallback(Screen0_ButtonWidget_Down, event_Screen0_ButtonWidget_Down_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen0_ButtonWidget_Down);

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
    Screen0_imgMchp = NULL;
    Screen0_btnQuickstart = NULL;
    Screen0_lblCounter = NULL;
    Screen0_ButtonWidget_Up = NULL;
    Screen0_ButtonWidget_Down = NULL;


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

