#include <wx/wx.h>
#include "UserManager.h"
#include "UserFrame.h"
#include <string>

std::string DataBaseAddress = "dbname=dfqugt45bplafp user=ueid349f444hpc password=p115197e8dec98b7fd9d5e32e93fbe0a6911b95fd5fd837d7614dd97d031cfe75 host=caij57unh724n3.cluster-czrs8kj4isg7.us-east-1.rds.amazonaws.com port=5432 sslmode=require";

UserManager manager;

class UserApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        manager.Load();
        UserFrame *frame = new UserFrame("Personal Journal", &manager);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(UserApp);
