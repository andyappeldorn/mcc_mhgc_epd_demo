#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen0_pnlBase;
leImageWidget* Screen0_imgMchp;
leButtonWidget* Screen0_btnMode;
leLabelWidget* Screen0_lblCounter;
leButtonWidget* Screen0_ButtonWidget_Up;
leButtonWidget* Screen0_ButtonWidget_Down;
leLabelWidget* Screen0_LabelTouchCoordinate;

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

    Screen0_btnMode = leButtonWidget_New();
    Screen0_btnMode->fn->setPosition(Screen0_btnMode, 20, 250);
    Screen0_btnMode->fn->setSize(Screen0_btnMode, 200, 60);
    Screen0_btnMode->fn->setScheme(Screen0_btnMode, &WhiteScheme);
    Screen0_btnMode->fn->setBackgroundType(Screen0_btnMode, LE_WIDGET_BACKGROUND_NONE);
    Screen0_btnMode->fn->setBorderType(Screen0_btnMode, LE_WIDGET_BORDER_NONE);
    Screen0_btnMode->fn->setToggleable(Screen0_btnMode, LE_TRUE);
    Screen0_btnMode->fn->setString(Screen0_btnMode, (leString*)&string_strMode);
    Screen0_btnMode->fn->setPressedImage(Screen0_btnMode, (leImage*)&btn2);
    Screen0_btnMode->fn->setReleasedImage(Screen0_btnMode, (leImage*)&btn);
    Screen0_btnMode->fn->setImagePosition(Screen0_btnMode, LE_RELATIVE_POSITION_BEHIND);
    Screen0_btnMode->fn->setReleasedEventCallback(Screen0_btnMode, event_Screen0_btnMode_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen0_btnMode);

    Screen0_lblCounter = leLabelWidget_New();
    Screen0_lblCounter->fn->setPosition(Screen0_lblCounter, 100, 80);
    Screen0_lblCounter->fn->setSize(Screen0_lblCounter, 141, 100);
    Screen0_lblCounter->fn->setBackgroundType(Screen0_lblCounter, LE_WIDGET_BACKGROUND_NONE);
    Screen0_lblCounter->fn->setHAlignment(Screen0_lblCounter, LE_HALIGN_CENTER);
    Screen0_lblCounter->fn->setString(Screen0_lblCounter, (leString*)&string_strCount);
    root0->fn->addChild(root0, (leWidget*)Screen0_lblCounter);

    Screen0_ButtonWidget_Up = leButtonWidget_New();
    Screen0_ButtonWidget_Up->fn->setPosition(Screen0_ButtonWidget_Up, 20, 49);
    Screen0_ButtonWidget_Up->fn->setSize(Screen0_ButtonWidget_Up, 80, 80);
    Screen0_ButtonWidget_Up->fn->setScheme(Screen0_ButtonWidget_Up, &WhiteScheme);
    Screen0_ButtonWidget_Up->fn->setBackgroundType(Screen0_ButtonWidget_Up, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Up->fn->setReleasedEventCallback(Screen0_ButtonWidget_Up, event_Screen0_ButtonWidget_Up_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen0_ButtonWidget_Up);

    Screen0_ButtonWidget_Down = leButtonWidget_New();
    Screen0_ButtonWidget_Down->fn->setPosition(Screen0_ButtonWidget_Down, 20, 142);
    Screen0_ButtonWidget_Down->fn->setSize(Screen0_ButtonWidget_Down, 80, 80);
    Screen0_ButtonWidget_Down->fn->setScheme(Screen0_ButtonWidget_Down, &WhiteScheme);
    Screen0_ButtonWidget_Down->fn->setBackgroundType(Screen0_ButtonWidget_Down, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Down->fn->setReleasedEventCallback(Screen0_ButtonWidget_Down, event_Screen0_ButtonWidget_Down_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen0_ButtonWidget_Down);

    Screen0_LabelTouchCoordinate = leLabelWidget_New();
    Screen0_LabelTouchCoordinate->fn->setPosition(Screen0_LabelTouchCoordinate, 0, 317);
    Screen0_LabelTouchCoordinate->fn->setSize(Screen0_LabelTouchCoordinate, 240, 40);
    Screen0_LabelTouchCoordinate->fn->setBackgroundType(Screen0_LabelTouchCoordinate, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_LabelTouchCoordinate);

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
    Screen0_btnMode = NULL;
    Screen0_lblCounter = NULL;
    Screen0_ButtonWidget_Up = NULL;
    Screen0_ButtonWidget_Down = NULL;
    Screen0_LabelTouchCoordinate = NULL;


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

