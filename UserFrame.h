// UserFrame.h
#ifndef USERFRAME_H
#define USERFRAME_H

#include <wx/wx.h>
#include "UserManager.h"

class UserFrame : public wxFrame
{
public:
    UserFrame(const wxString &title, UserManager* manager);
    ~UserFrame();

private:
    UserManager* userManager;
    wxButton *btnCloseApp;
    wxListBox *userListBox;
    wxButton *btnLogin;
    wxButton *btnAddUser;
    wxButton *btnDeleteUser;
    wxButton *btnForgotPassword;
    wxStaticText *userInfoText;

    void OnLogin(wxCommandEvent &event);
    void OnAddUser(wxCommandEvent &event);
    void OnDeleteUser(wxCommandEvent &event);
    void OnForgotPassword(wxCommandEvent &event);
    void OnUserSelection(wxCommandEvent &event);
    void OnCloseApp(wxCommandEvent &event);
    void UpdateUserInfo();

    wxDECLARE_EVENT_TABLE();
};

#endif
