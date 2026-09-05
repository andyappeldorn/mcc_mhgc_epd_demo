#include "gfx/legato/generated/screen/le_gen_screen_Screen1.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen1_pnlBase;
leImageWidget* Screen1_imgMchp;
leButtonWidget* Screen1_btnBack;
leImageWidget* Screen1_ImageWidgetQRCode;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen1(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen1(void)
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

    Screen1_pnlBase = leWidget_New();
    Screen1_pnlBase->fn->setPosition(Screen1_pnlBase, 0, 0);
    Screen1_pnlBase->fn->setSize(Screen1_pnlBase, 240, 360);
    Screen1_pnlBase->fn->setScheme(Screen1_pnlBase, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen1_pnlBase);

    Screen1_imgMchp = leImageWidget_New();
    Screen1_imgMchp->fn->setPosition(Screen1_imgMchp, 0, 0);
    Screen1_imgMchp->fn->setSize(Screen1_imgMchp, 240, 45);
    Screen1_imgMchp->fn->setBackgroundType(Screen1_imgMchp, LE_WIDGET_BACKGROUND_NONE);
    Screen1_imgMchp->fn->setBorderType(Screen1_imgMchp, LE_WIDGET_BORDER_NONE);
    Screen1_imgMchp->fn->setImage(Screen1_imgMchp, (leImage*)&imgMchp);
    root0->fn->addChild(root0, (leWidget*)Screen1_imgMchp);

    Screen1_btnBack = leButtonWidget_New();
    Screen1_btnBack->fn->setPosition(Screen1_btnBack, 27, 257);
    Screen1_btnBack->fn->setSize(Screen1_btnBack, 200, 60);
    Screen1_btnBack->fn->setScheme(Screen1_btnBack, &WhiteScheme);
    Screen1_btnBack->fn->setBackgroundType(Screen1_btnBack, LE_WIDGET_BACKGROUND_NONE);
    Screen1_btnBack->fn->setBorderType(Screen1_btnBack, LE_WIDGET_BORDER_NONE);
    Screen1_btnBack->fn->setToggleable(Screen1_btnBack, LE_TRUE);
    Screen1_btnBack->fn->setString(Screen1_btnBack, (leString*)&string_strBack);
    Screen1_btnBack->fn->setPressedImage(Screen1_btnBack, (leImage*)&btn2);
    Screen1_btnBack->fn->setReleasedImage(Screen1_btnBack, (leImage*)&btn);
    Screen1_btnBack->fn->setImagePosition(Screen1_btnBack, LE_RELATIVE_POSITION_BEHIND);
    root0->fn->addChild(root0, (leWidget*)Screen1_btnBack);

    Screen1_ImageWidgetQRCode = leImageWidget_New();
    Screen1_ImageWidgetQRCode->fn->setPosition(Screen1_ImageWidgetQRCode, 28, 53);
    Screen1_ImageWidgetQRCode->fn->setSize(Screen1_ImageWidgetQRCode, 191, 190);
    Screen1_ImageWidgetQRCode->fn->setBackgroundType(Screen1_ImageWidgetQRCode, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageWidgetQRCode->fn->setBorderType(Screen1_ImageWidgetQRCode, LE_WIDGET_BORDER_NONE);
    Screen1_ImageWidgetQRCode->fn->setImage(Screen1_ImageWidgetQRCode, (leImage*)&QR);
    root0->fn->addChild(root0, (leWidget*)Screen1_ImageWidgetQRCode);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_MONOCHROME);

    Screen1_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen1(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Screen1_OnUpdate(); // raise event
}

void screenHide_Screen1(void)
{
    Screen1_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen1_pnlBase = NULL;
    Screen1_imgMchp = NULL;
    Screen1_btnBack = NULL;
    Screen1_ImageWidgetQRCode = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen1(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen1(uint32_t lyrIdx)
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

