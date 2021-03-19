#include "OptionsDLG.h"
/*
//(*InternalHeaders(OptionsDLG)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(OptionsDLG)
const long OptionsDLG::ID_CHOICE1 = wxNewId();
const long OptionsDLG::ID_STATICTEXT1 = wxNewId();
const long OptionsDLG::ID_BUTTON1 = wxNewId();
const long OptionsDLG::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(OptionsDLG,wxDialog)
	//(*EventTable(OptionsDLG)
	//*)
END_EVENT_TABLE()

OptionsDLG::OptionsDLG(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(OptionsDLG)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(514,450));
	Move(wxDefaultPosition);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(192,216), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->Append(_("OpenGL"));
	Choice1->Append(_("SDL 2"));
	Choice1->Append(_("GDI +"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("WindowBackend"), wxPoint(96,216), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Start"), wxPoint(432,416), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Label"), wxPoint(344,416), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OptionsDLG::OnButton1Click);
	//*)
}

OptionsDLG::~OptionsDLG()
{
	//(*Destroy(OptionsDLG)
	//*)
}


void OptionsDLG::OnButton1Click(wxCommandEvent& event)
{

}
*/
