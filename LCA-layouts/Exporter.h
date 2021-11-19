#ifndef EXPORTER_H
#define EXPORTER_H

#include <string>
#include <wx/wx.h>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <vector>

using namespace std;

class Exporter
{
private:
	vector<wxButton*> keys;
	string title;
	static map<char, string> xmodmap_keys;
	static vector<string> autohotkey_keys;
	static map<char, string> klc_keys;
	static map<int, int> mac_keys;
	static map<char, string> mac_upper;

public:
	Exporter(const string& title, vector<wxButton*>& keys) {
		this->title = title;
		this->keys = keys;
	}

	void Export() {
		wxFFileOutputStream out(title + ".zip");
		wxZipOutputStream zip(out);
		wxTextOutputStream txt(zip);
		
		wxString sep(wxFileName::GetPathSeparator());
		
		zip.PutNextEntry("xmodmap" + sep + "xmodmap." + title);
		Export_xmodmap(txt);
		
		zip.PutNextEntry("autohotkey" + sep + "QWERTY_to_" + title + ".ahk");
		Export_autohotkey(txt);

		zip.PutNextEntry("windows" + sep + title + ".klc");
		Export_windows(txt);

		zip.PutNextEntry("mac" + sep + title + ".keylayout");
		Export_mac(txt);
	}

	void Export_xmodmap(wxTextOutputStream& txt) {
		txt << "! xmodmap for the " + title + " layout" << endl << endl
			<< "keycode  49 =        grave    asciitilde       dead_tilde        asciitilde" << endl
			<< "keycode  10 =            1        exclam       exclamdown       onesuperior" << endl
			<< "keycode  11 =            2            at        masculine       twosuperior" << endl
			<< "keycode  12 =            3    numbersign      ordfeminine     threesuperior" << endl
			<< "keycode  13 =            4        dollar             cent          sterling" << endl
			<< "keycode  14 =            5       percent         EuroSign               yen" << endl
			<< "keycode  15 =            6   asciicircum          hstroke           Hstroke" << endl
			<< "keycode  16 =            7     ampersand              eth               ETH" << endl
			<< "keycode  17 =            8      asterisk            thorn             THORN" << endl
			<< "keycode  18 =            9     parenleft   leftsinglequotemark   leftdoublequotemark" << endl
			<< "keycode  19 =            0    parenright  rightsinglequotemark   rightdoublequotemark" << endl
			<< "keycode  20 =        minus    underscore           endash            emdash" << endl
			<< "keycode  21 =        equal          plus         multiply          division" << endl << endl;

		map<char, string>::iterator xmodmap_key;
		for (int i = 0; i < keys.size(); i++)
		{
			int id = keys[i]->GetId();
			xmodmap_key = xmodmap_keys.find(keys[i]->GetLabel().c_str()[0]);
			if (xmodmap_key != xmodmap_keys.end())
			{
				txt << "keycode  " << id << " =" << xmodmap_key->second << endl;
			}
			if (id == 51 || id == 48 || id == 61) {
				txt << endl;
			}
		}

		txt << "keycode  66 =    BackSpace     BackSpace        BackSpace         BackSpace" << endl
			<< "keycode  94 =        minus    underscore           endash            emdash" << endl
			<< "keycode  65 =        space         space            space      nobreakspace" << endl
			<< "keycode 113 =  Mode_switch   Mode_switch" << endl
			<< "clear Lock" << endl 
			<< endl
			<< "!clear Shift" << endl
			<< "!clear Control" << endl
			<< "!clear Mod1" << endl
			<< "!clear Mod2" << endl
			<< "!clear Mod3" << endl
			<< "!clear Mod4" << endl
			<< "!clear Mod5" << endl 
			<< endl
			<< "!add    Shift = Shift_L Shift_R" << endl
			<< "!add    Control = Control_L Control_R" << endl
			<< "!add    Mod1 = Alt_L Alt_R" << endl
			<< "!add    Mod2 = Num_Lock" << endl
			<< "!add    Mod4 = Meta_L Meta_R" << endl
			<< "!add    Mod5 = Scroll_Lock" << endl << endl
			<< "!keycode   9 = Escape" << endl
			<< "!keycode  22 = BackSpace Terminate_Server" << endl
			<< "!keycode  23 = Tab ISO_Left_Tab" << endl
			<< "!keycode  36 = Return" << endl
			<< "!keycode  37 = Control_L" << endl
			<< "!keycode  50 = Shift_L" << endl
			<< "!keycode  62 = Shift_R" << endl
			<< "!keycode  63 = KP_Multiply XF86_ClearGrab" << endl
			<< "!keycode  64 = Alt_L Meta_L" << endl
			<< "!keycode  67 = F1 XF86_Switch_VT_1" << endl
			<< "!keycode  68 = F2 XF86_Switch_VT_2" << endl
			<< "!keycode  69 = F3 XF86_Switch_VT_3" << endl
			<< "!keycode  70 = F4 XF86_Switch_VT_4" << endl
			<< "!keycode  71 = F5 XF86_Switch_VT_5" << endl
			<< "!keycode  72 = F6 XF86_Switch_VT_6" << endl
			<< "!keycode  73 = F7 XF86_Switch_VT_7" << endl
			<< "!keycode  74 = F8 XF86_Switch_VT_8" << endl
			<< "!keycode  75 = F9 XF86_Switch_VT_9" << endl
			<< "!keycode  76 = F10 XF86_Switch_VT_10" << endl
			<< "!keycode  95 = F11 XF86_Switch_VT_11" << endl
			<< "!keycode  96 = F12 XF86_Switch_VT_12" << endl
			<< "!keycode  77 = Num_Lock Pointer_EnableKeys" << endl
			<< "!keycode  78 = Scroll_Lock" << endl
			<< "!keycode  79 = KP_Home KP_7" << endl
			<< "!keycode  80 = KP_Up KP_8" << endl
			<< "!keycode  81 = KP_Prior KP_9" << endl
			<< "!keycode  82 = KP_Subtract XF86_Prev_VMode" << endl
			<< "!keycode  83 = KP_Left KP_4" << endl
			<< "!keycode  84 = KP_Begin KP_5" << endl
			<< "!keycode  85 = KP_Right KP_6" << endl
			<< "!keycode  86 = KP_Add XF86_Next_VMode" << endl
			<< "!keycode  87 = KP_End KP_1" << endl
			<< "!keycode  88 = KP_Down KP_2" << endl
			<< "!keycode  89 = KP_Next KP_3" << endl
			<< "!keycode  90 = KP_Insert KP_0" << endl
			<< "!keycode  91 = KP_Delete KP_Decimal" << endl
			<< "!keycode  92 = Print Sys_Req" << endl
			<< "!keycode  93 = Mode_switch" << endl
			<< "!keycode  97 = Home" << endl
			<< "!keycode  98 = Up" << endl
			<< "!keycode  99 = Prior" << endl
			<< "!keycode 100 = Left" << endl
			<< "!keycode 102 = Right" << endl
			<< "!keycode 103 = End" << endl
			<< "!keycode 104 = Down" << endl
			<< "!keycode 105 = Next" << endl
			<< "!keycode 106 = Insert" << endl
			<< "!keycode 107 = Delete" << endl
			<< "!keycode 108 = KP_Enter" << endl
			<< "!keycode 109 = Control_R" << endl
			<< "!keycode 110 = Pause Break" << endl
			<< "!keycode 111 = Print Sys_Req" << endl
			<< "!keycode 112 = KP_Divide XF86_Ungrab" << endl
			<< "!keycode 114 = Pause Break" << endl
			<< "!keycode 115 = Super_L" << endl
			<< "!keycode 116 = Super_R" << endl
			<< "!keycode 117 = Menu" << endl
			<< "!keycode 124 = ISO_Level3_Shift" << endl
			<< "!keycode 125 = NoSymbol Alt_L" << endl
			<< "!keycode 126 = KP_Equal" << endl
			<< "!keycode 127 = NoSymbol Super_L" << endl
			<< "!keycode 128 = NoSymbol Hyper_L" << endl
			<< "!keycode 156 = NoSymbol Meta_L" << endl 
			<< endl
			<< "!keycode   8 =" << endl
			<< "!keycode 101 =" << endl
			<< "!keycode 118 =" << endl
			<< "!keycode 119 =" << endl
			<< "!keycode 120 =" << endl
			<< "!keycode 121 =" << endl
			<< "!keycode 122 =" << endl
			<< "!keycode 123 =" << endl
			<< "!keycode 129 =" << endl
			<< "!keycode 130 =" << endl
			<< "!keycode 131 =" << endl
			<< "!keycode 132 =" << endl
			<< "!keycode 133 =" << endl
			<< "!keycode 134 =" << endl
			<< "!keycode 135 =" << endl
			<< "!keycode 136 =" << endl
			<< "!keycode 137 =" << endl
			<< "!keycode 138 =" << endl
			<< "!keycode 139 =" << endl
			<< "!keycode 140 =" << endl
			<< "!keycode 141 =" << endl
			<< "!keycode 142 =" << endl
			<< "!keycode 143 =" << endl
			<< "!keycode 144 =" << endl
			<< "!keycode 145 =" << endl
			<< "!keycode 146 =" << endl
			<< "!keycode 147 =" << endl
			<< "!keycode 148 =" << endl
			<< "!keycode 149 =" << endl
			<< "!keycode 150 =" << endl
			<< "!keycode 151 =" << endl
			<< "!keycode 152 =" << endl
			<< "!keycode 153 =" << endl
			<< "!keycode 154 =" << endl
			<< "!keycode 155 =" << endl
			<< "!keycode 157 =" << endl
			<< "!keycode 158 =" << endl
			<< "!keycode 159 =" << endl
			<< "!keycode 160 =" << endl
			<< "!keycode 161 =" << endl
			<< "!keycode 162 =" << endl
			<< "!keycode 163 =" << endl
			<< "!keycode 164 =" << endl
			<< "!keycode 165 =" << endl
			<< "!keycode 166 =" << endl
			<< "!keycode 167 =" << endl
			<< "!keycode 168 =" << endl
			<< "!keycode 169 =" << endl
			<< "!keycode 170 =" << endl
			<< "!keycode 171 =" << endl
			<< "!keycode 172 =" << endl
			<< "!keycode 173 =" << endl
			<< "!keycode 174 =" << endl
			<< "!keycode 175 =" << endl
			<< "!keycode 176 =" << endl
			<< "!keycode 177 =" << endl
			<< "!keycode 178 =" << endl
			<< "!keycode 179 =" << endl
			<< "!keycode 180 =" << endl
			<< "!keycode 181 =" << endl
			<< "!keycode 182 =" << endl
			<< "!keycode 183 =" << endl
			<< "!keycode 184 =" << endl
			<< "!keycode 185 =" << endl
			<< "!keycode 186 =" << endl
			<< "!keycode 187 =" << endl
			<< "!keycode 188 =" << endl
			<< "!keycode 189 =" << endl
			<< "!keycode 190 =" << endl
			<< "!keycode 191 =" << endl
			<< "!keycode 192 =" << endl
			<< "!keycode 193 =" << endl
			<< "!keycode 194 =" << endl
			<< "!keycode 195 =" << endl
			<< "!keycode 196 =" << endl
			<< "!keycode 197 =" << endl
			<< "!keycode 198 =" << endl
			<< "!keycode 199 =" << endl
			<< "!keycode 200 =" << endl
			<< "!keycode 201 =" << endl
			<< "!keycode 202 =" << endl
			<< "!keycode 203 =" << endl
			<< "!keycode 204 =" << endl
			<< "!keycode 205 =" << endl
			<< "!keycode 206 =" << endl
			<< "!keycode 207 =" << endl
			<< "!keycode 208 =" << endl
			<< "!keycode 209 =" << endl
			<< "!keycode 210 =" << endl
			<< "!keycode 211 =" << endl
			<< "!keycode 212 =" << endl
			<< "!keycode 213 =" << endl
			<< "!keycode 214 =" << endl
			<< "!keycode 215 =" << endl
			<< "!keycode 216 =" << endl
			<< "!keycode 217 =" << endl
			<< "!keycode 218 =" << endl
			<< "!keycode 219 =" << endl
			<< "!keycode 220 =" << endl
			<< "!keycode 221 =" << endl
			<< "!keycode 222 =" << endl
			<< "!keycode 223 =" << endl
			<< "!keycode 224 =" << endl
			<< "!keycode 225 =" << endl
			<< "!keycode 226 =" << endl
			<< "!keycode 227 =" << endl
			<< "!keycode 228 =" << endl
			<< "!keycode 229 =" << endl
			<< "!keycode 230 =" << endl
			<< "!keycode 231 =" << endl
			<< "!keycode 232 =" << endl
			<< "!keycode 233 =" << endl
			<< "!keycode 234 =" << endl
			<< "!keycode 235 =" << endl
			<< "!keycode 236 =" << endl
			<< "!keycode 237 =" << endl
			<< "!keycode 238 =" << endl
			<< "!keycode 239 =" << endl
			<< "!keycode 240 =" << endl
			<< "!keycode 241 =" << endl
			<< "!keycode 242 =" << endl
			<< "!keycode 243 =" << endl
			<< "!keycode 244 =" << endl << "!keycode 245 =" << endl << "!keycode 246 =" << endl << "!keycode 247 =" << endl
			<< "!keycode 248 =" << endl << "!keycode 249 =" << endl << "!keycode 250 =" << endl << "!keycode 251 =" << endl
			<< "!keycode 252 =" << endl << "!keycode 253 =" << endl << "!keycode 254 =" << endl << "!keycode 255 =" << endl;
	}

	void Export_autohotkey(wxTextOutputStream& txt) {
		txt << "; " + title + " layout for AutoHotkey (MS Windows)" << endl << endl
			<< "; For this to work you have to make sure that the US (QWERTY) layout is installed," << endl
			<< "; that is set as the default layout, and that it is set as the current layout." << endl
			<< "; Otherwise some of the key mappings will be wrong." << endl << endl
			<< ";`::`" << endl << ";1::1" << endl << ";2::2" << endl << ";3::3"
			<< endl << ";4::4" << endl << ";5::5" << endl << ";6::6" << endl
			<< ";7::7" << endl << ";8::8" << endl << ";9::9" << endl << ";0::0"
			<< endl << ";-::-" << endl << ";=::=" << endl;

		int ahk_index = 0;
		for (int i = 0; i < keys.size() && ahk_index < Exporter::autohotkey_keys.size(); i++)
		{
			if (keys[i]->GetId() > 0) {
				if (keys[i]->GetLabel() == ";") {
					txt << Exporter::autohotkey_keys[ahk_index] << "::`" << keys[i]->GetLabel() << endl;
				}
				else {
					txt << Exporter::autohotkey_keys[ahk_index] << "::" << keys[i]->GetLabel() << endl;
				}
				ahk_index++;
			}
		}
	}

	void Export_windows(wxTextOutputStream& txt) {
		// info
		txt << "KBD \"EN " + title + "\"" << endl << endl
			<< "COPYRIGHT	\"(c)2021 Company\"" << endl << endl
			<< "COMPANY	\"Company\"" << endl << endl
			<< "LOCALENAME	\"en-US\"" << endl << endl
			<< "LOCALEID	\"00000409\"" << endl << endl
			<< "VERSION	1.0" << endl << endl
			<< "SHIFTSTATE" << endl << endl
			<< "0	//Column 4" << endl
			<< "1	//Column 5 : Shft" << endl
			<< "2	//Column 6 :       Ctrl" << endl << endl
			<< "LAYOUT    ; an extra '@' at the end is a dead key" << endl << endl
			<< "//SC	VK_		Cap	0	1	2" << endl
			<< "//--	----		----	----	----	----" << endl << endl;

		// num row
		txt << "02	1		0	1	0021 -1		// DIGIT ONE, EXCLAMATION MARK, <none>" << endl
			<< "03	2		0	2	0040 -1		// DIGIT TWO, COMMERCIAL AT, <none>" << endl
			<< "04	3		0	3	0023 -1		// DIGIT THREE, NUMBER SIGN, <none>" << endl
			<< "05	4		0	4	0024 -1		// DIGIT FOUR, DOLLAR SIGN, <none>" << endl
			<< "06	5		0	5	0025 -1		// DIGIT FIVE, PERCENT SIGN, <none>" << endl
			<< "07	6		0	6	005e -1		// DIGIT SIX, CIRCUMFLEX ACCENT, <none>" << endl
			<< "08	7		0	7	0026 -1		// DIGIT SEVEN, AMPERSAND, <none>" << endl
			<< "09	8		0	8	002a -1		// DIGIT EIGHT, ASTERISK, <none>" << endl
			<< "0a	9		0	9	0028 -1		// DIGIT NINE, LEFT PARENTHESIS, <none>" << endl
			<< "0b	0		0	0	0029 -1		// DIGIT ZERO, RIGHT PARENTHESIS, <none>" << endl
			<< "0c	OEM_MINUS	0	002d	005f - 1		// HYPHEN-MINUS, LOW LINE, <none>" << endl
			<< "0d	OEM_PLUS	0	003d	002b - 1		// EQUALS SIGN, PLUS SIGN, <none>" << endl;

		map<char, string>::iterator klc_key;
		int i = 0;
		while (i < 10) {
			klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
			if (klc_key != klc_keys.end())
			{
				txt << (i + 10) << " " << klc_key->second << endl;
			}
			i++;
		}

		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "1a " << klc_key->second << endl;
		i++;
		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "1b " << klc_key->second << endl;
		i += 2;
		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "1e " << klc_key->second << endl;
		i++;
		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "1f " << klc_key->second << endl;
		i++;

		while (i < 24) {
			klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
			if (klc_key != klc_keys.end())
			{
				txt << (i + 5) << " " << klc_key->second << endl;
			}
			i++;
		}

		txt << "29 OEM_3		0	0060	007e	-1		// GRAVE ACCENT, TILDE, <none>" << endl
			<< "2b OEM_5		0	005c	007c	001c		// REVERSE SOLIDUS, VERTICAL LINE, INFORMATION SEPARATOR FOUR" << endl;

		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "2c " << klc_key->second << endl;
		i++;
		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "2d " << klc_key->second << endl;
		i++;
		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "2e " << klc_key->second << endl;
		i++;
		klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
		txt << "2f " << klc_key->second << endl;
		i++;

		while (i < 34) {
			klc_key = klc_keys.find(keys[i]->GetLabel().c_str()[0]);
			if (klc_key != klc_keys.end())
			{
				txt << (i + 2) << " " << klc_key->second << endl;
			}
			i++;
		}

		txt << "39 SPACE		0	0020	0020	0020		// SPACE, SPACE, SPACE" << endl
			<< "56 OEM_102	0	005c	007c	001c		// REVERSE SOLIDUS, VERTICAL LINE, INFORMATION SEPARATOR FOUR" << endl
			<< "53 DECIMAL	0	002e	002e	-1		// FULL STOP, FULL STOP, " << endl << endl
			<< "KEYNAME" << endl << endl << "01	Esc" << endl << "0e	Backspace" << endl << "0f	Tab" << endl << "1c	Enter" << endl << "1d	Ctrl" << endl
			<< "2a	Shift" << endl << "36	\"Right Shift\"" << endl << "37	\"Num * \"" << endl << "38	Alt" << endl << "39	Space" << endl << "3a	\"Caps Lock\""
			<< endl << "3b	F1" << endl << "3c	F2" << endl << "3d	F3" << endl << "3e	F4" << endl << "3f	F5" << endl << "40	F6" << endl << "41	F7" << endl
			<< "42	F8" << endl << "43	F9" << endl << "44	F10" << endl << "45	Pause" << endl << "46	\"Scroll Lock\"" << endl << "47	\"Num 7\"" << endl
			<< "48	\"Num 8\"" << endl << "49	\"Num 9\"" << endl << "4a	\"Num -\"" << endl << "4b	\"Num 4\"" << endl << "4c	\"Num 5\"" << endl
			<< "4d	\"Num 6\"" << endl << "4e	\"Num + \"" << endl << "4f	\"Num 1\"" << endl << "50	\"Num 2\"" << endl << "51	\"Num 3\"" << endl
			<< "52	\"Num 0\"" << endl << "53	\"Num Del\"" << endl << "54	\"Sys Req\"" << endl << "57	F11" << endl << "58	F12" << endl << "7c	F13" << endl
			<< "7d	F14" << endl << "7e	F15" << endl << "7f	F16" << endl << "80	F17" << endl << "81	F18" << endl << "82	F19" << endl << "83	F20" << endl << "84	F21"
			<< endl << "85	F22" << endl << "86	F23" << endl << "87	F24" << endl << endl << "KEYNAME_EXT" << endl << endl
			<< "1c	\"Num Enter\"" << endl << "1d	\"Right Ctrl\"" << endl << "35	\"Num /\"" << endl << "37	\"Prnt Scrn\"" << endl << "38	\"Right Alt\"" << endl
			<< "45	\"Num Lock\"" << endl << "46	Break" << endl << "47	Home" << endl << "48	Up" << endl << "49	\"Page Up\"" << endl << "4b	Left" << endl
			<< "4d	Right" << endl << "4f	End" << endl << "50	Down" << endl << "51	\"Page Down\"" << endl << "52	Insert" << endl << "53	Delete" << endl
			<< "54 < 00 >" << endl << "56	Help" << endl << "5b	\"Left Windows\"" << endl << "5c	\"Right Windows\"" << endl << "5d	Application" << endl << endl
			<< "DESCRIPTIONS" << endl << endl
			<< "0409	United States " + title << endl << endl << "LANGUAGENAMES" << endl << endl << "0409	English (United States)" << endl << endl << "ENDKBD";
	}

	void Export_mac(wxTextOutputStream& txt) {
		txt << "<?xml version=\"1.1\" encoding=\"UTF-8\"?>" << endl
			<< "<!DOCTYPE keyboard SYSTEM \"file://localhost/System/Library/DTDs/KeyboardLayout.dtd\">" << endl
			<< "<keyboard group=\"126\" id=\"-8853\" name=\"" + title + "\" maxout=\"1\">" << endl
			<< "	<layouts>" << endl
			<< "		<layout first=\"0\" last=\"17\" mapSet=\"ANSI\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"18\" last=\"18\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"21\" last=\"23\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"30\" last=\"30\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"33\" last=\"33\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"36\" last=\"36\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"194\" last=\"194\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"197\" last=\"197\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"200\" last=\"201\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "        <layout first=\"206\" last=\"207\" mapSet=\"JIS\" modifiers=\"Modifiers\"/>" << endl
			<< "    </layouts>" << endl
			<< "    <modifierMap id=\"Modifiers\" defaultIndex=\"6\">" << endl // Modifiers
			<< "        <keyMapSelect mapIndex=\"0\">" << endl
			<< "            <modifier keys=\"\"/>" << endl
			<< "        </keyMapSelect>" << endl
			<< "        <keyMapSelect mapIndex=\"1\">" << endl
			<< "            <modifier keys=\"anyShift\"/>" << endl // with Shift
			<< "        </keyMapSelect>" << endl
			<< "        <keyMapSelect mapIndex=\"2\">" << endl
			<< "            <modifier keys=\"anyOption\"/>" << endl
			<< "        </keyMapSelect>" << endl
			<< "        <keyMapSelect mapIndex=\"3\">" << endl
			<< "            <modifier keys=\"anyShift caps? anyOption\"/>" << endl
			<< "        </keyMapSelect>" << endl
			<< "        <keyMapSelect mapIndex=\"4\">" << endl
			<< "            <modifier keys=\"command\"/>" << endl
			<< "        </keyMapSelect>" << endl
			<< "        <keyMapSelect mapIndex=\"5\">" << endl
			<< "            <modifier keys=\"caps\"/>" << endl
			<< "        </keyMapSelect>" << endl
			<< "        <keyMapSelect mapIndex=\"6\">" << endl
			<< "            <modifier keys=\"anyControl\"/>" << endl
			<< "        </keyMapSelect>" << endl
			<< "	</modifierMap>" << endl;

	
		int index = 0;
		txt << "    <keyMapSet id=\"ANSI\">" << endl;
		for (int index = 0; index < 7; index++) {
			txt << "        <keyMap index=\"" << index << "\">" << endl;

			if (index == 2 || index == 3 || index == 6) {
				txt << "            <key code=\"0\" output=\"\"/>" << endl
					<< "            <key code=\"36\" output=\"&#x000D;\"/>" << endl
					<< "            <key code=\"48\" output=\"&#x0009;\"/>" << endl
					<< "            <key code=\"51\" output=\"&#x0008;\"/>" << endl
					<< "            <key code=\"53\" output=\"&#x001B;\"/>" << endl
					<< "            <key code=\"64\" output=\"&#x0010;\"/>" << endl
					<< "            <key code=\"66\" output=\"&#x001D;\"/>" << endl
					<< "            <key code=\"70\" output=\"&#x001C;\"/>" << endl
					<< "            <key code=\"71\" output=\"&#x001B;\"/>" << endl
					<< "            <key code=\"72\" output=\"&#x001F;\"/>" << endl
					<< "            <key code=\"76\" output=\"&#x0003;\"/>" << endl
					<< "            <key code=\"77\" output=\"&#x001E;\"/>" << endl
					<< "            <key code=\"79\" output=\"&#x0010;\"/>" << endl
					<< "            <key code=\"80\" output=\"&#x0010;\"/>" << endl;
			}
			else 
			{
				if (index == 0 || index == 4) // lowercase
				{
					for (int code = 0; code < 10; code++)
					{
						txt << "            <key code=\"" << code << "\" output=\"" << keys[mac_keys.find(code)->second]->GetLabel() << "\"/>" << endl;
					}
					txt << "            <key code=\"10\" output=\"§\"/>" << endl;
					for (int code = 11; code < 18; code++)
					{
						txt << "            <key code=\"" << code << "\" output=\"" << keys[mac_keys.find(code)->second]->GetLabel() << "\"/>" << endl;
					}
					txt << "            <key code=\"18\" output=\"1\"/>" << endl
						<< "            <key code=\"19\" output=\"2\"/>" << endl
						<< "            <key code=\"20\" output=\"3\"/>" << endl
						<< "            <key code=\"21\" output=\"4\"/>" << endl
						<< "            <key code=\"22\" output=\"6\"/>" << endl
						<< "            <key code=\"23\" output=\"5\"/>" << endl
						<< "            <key code=\"24\" output=\"=\"/>" << endl
						<< "            <key code=\"25\" output=\"9\"/>" << endl
						<< "            <key code=\"26\" output=\"7\"/>" << endl
						<< "            <key code=\"27\" output=\"-\"/>" << endl
						<< "            <key code=\"28\" output=\"8\"/>" << endl
						<< "            <key code=\"29\" output=\"0\"/>" << endl;
					for (int code = 30; code < 36; code++) {
						txt << "            <key code=\"" << code << "\" output=\"" << keys[mac_keys.find(code)->second]->GetLabel() << "\"/>" << endl;
					}
					txt << "            <key code=\"36\" output=\"&#x000D;\"/>" << endl;
					for (int code = 37; code < 42; code++) {
						txt << "            <key code=\"" << code << "\" output=\"" << keys[mac_keys.find(code)->second]->GetLabel() << "\"/>" << endl;
					}
					txt << "            <key code=\"42\" output=\"\\\"/>" << endl;
					for (int code = 43; code < 48; code++) {
						txt << "            <key code=\"" << code << "\" output=\"" << keys[mac_keys.find(code)->second]->GetLabel() << "\"/>" << endl;
					}
				}
				else
				{
					map<char, string>::iterator paste_char;
					for (int code = 0; code < 10; code++)
					{
						paste_char = mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]);
						if (paste_char != mac_upper.end()) {
							txt << "            <key code=\"" << code << "\" output=\"" << mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0])->second << "\"/>" << endl;
						}
						else {
							txt << "            <key code=\"" << code << "\" output=\"" << (char)toupper(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]) << "\"/>" << endl;
						}
					}
					txt << "            <key code=\"10\" output=\"§\"/>" << endl;
					for (int code = 11; code < 18; code++)
					{
						paste_char = mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]);
						if (paste_char != mac_upper.end()) {
							txt << "            <key code=\"" << code << "\" output=\"" << mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0])->second << "\"/>" << endl;
						}
						else {
							txt << "            <key code=\"" << code << "\" output=\"" << (char)toupper(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]) << "\"/>" << endl;
						}
					}
					txt << "            <key code=\"18\" output=\"!\"/>" << endl
						<< "            <key code=\"19\" output=\"@\"/>" << endl
						<< "            <key code=\"20\" output=\"#\"/>" << endl
						<< "            <key code=\"21\" output=\"$\"/>" << endl
						<< "            <key code=\"22\" output=\"^\"/>" << endl
						<< "            <key code=\"23\" output=\"%\"/>" << endl
						<< "            <key code=\"24\" output=\"+\"/>" << endl
						<< "            <key code=\"25\" output=\"(\"/>" << endl
						<< "            <key code=\"26\" output=\"&#x0026;\"/>" << endl
						<< "            <key code=\"27\" output=\"_\"/>" << endl
						<< "            <key code=\"28\" output=\"*\"/>" << endl
						<< "            <key code=\"29\" output=\")\"/>" << endl;
					for (int code = 30; code < 36; code++) {
						paste_char = mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]);
						if (paste_char != mac_upper.end()) {
							txt << "            <key code=\"" << code << "\" output=\"" << mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0])->second << "\"/>" << endl;
						}
						else {
							txt << "            <key code=\"" << code << "\" output=\"" << (char)toupper(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]) << "\"/>" << endl;
						}
					}
					txt << "            <key code=\"36\" output=\"&#x000D;\"/>" << endl;
					for (int code = 37; code < 42; code++) {
						paste_char = mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]);
						if (paste_char != mac_upper.end()) {
							txt << "            <key code=\"" << code << "\" output=\"" << mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0])->second << "\"/>" << endl;
						}
						else {
							txt << "            <key code=\"" << code << "\" output=\"" << (char)toupper(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]) << "\"/>" << endl;
						}
					}
					txt << "            <key code=\"42\" output=\"|\"/>" << endl;
					for (int code = 43; code < 48; code++) {
						paste_char = mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]);
						if (paste_char != mac_upper.end()) {
							txt << "            <key code=\"" << code << "\" output=\"" << mac_upper.find(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0])->second << "\"/>" << endl;
						}
						else {
							txt << "            <key code=\"" << code << "\" output=\"" << (char)toupper(keys[mac_keys.find(code)->second]->GetLabel().c_str()[0]) << "\"/>" << endl;
						}
					}
				}

				txt << "            <key code=\"48\" output=\"&#x0009;\"/>" << endl
					<< "            <key code=\"49\" output=\" \"/>" << endl
					<< "            <key code=\"50\" output=\"`\"/>" << endl
					<< "            <key code=\"51\" output=\"&#x0008;\"/>" << endl
					<< "            <key code=\"53\" output=\"&#x001B;\"/>" << endl
					<< "            <key code=\"64\" output=\"&#x0010;\"/>" << endl
					<< "            <key code=\"65\" output=\"\"/>" << endl
					<< "            <key code=\"66\" output=\"&#x001D;\"/>" << endl
					<< "            <key code=\"67\" output=\"*\"/>" << endl
					<< "            <key code=\"69\" output=\"+\"/>" << endl
					<< "            <key code=\"70\" output=\"&#x001C;\"/>" << endl
					<< "            <key code=\"71\" output=\"&#x001B;\"/>" << endl
					<< "            <key code=\"72\" output=\"&#x001F;\"/>" << endl
					<< "            <key code=\"75\" output=\"/\"/>" << endl
					<< "            <key code=\"76\" output=\"&#x0003;\"/>" << endl
					<< "            <key code=\"77\" output=\"&#x001E;\"/>" << endl
					<< "            <key code=\"78\" output=\"-\"/>" << endl
					<< "            <key code=\"79\" output=\"&#x0010;\"/>" << endl
					<< "            <key code=\"80\" output=\"&#x0010;\"/>" << endl
					<< "            <key code=\"81\" output=\"=\"/>" << endl
					<< "            <key code=\"82\" output=\"0\"/>" << endl
					<< "            <key code=\"83\" output=\"1\"/>" << endl
					<< "            <key code=\"84\" output=\"2\"/>" << endl
					<< "            <key code=\"85\" output=\"3\"/>" << endl
					<< "            <key code=\"86\" output=\"4\"/>" << endl
					<< "            <key code=\"87\" output=\"5\"/>" << endl
					<< "            <key code=\"88\" output=\"6\"/>" << endl
					<< "            <key code=\"89\" output=\"7\"/>" << endl
					<< "            <key code=\"91\" output=\"8\"/>" << endl
					<< "            <key code=\"92\" output=\"9\"/>" << endl;
			}
			
			txt << "            <key code=\"96\" output=\"&#x0010;\"/>" << endl 
				<< "            <key code=\"97\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"98\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"99\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"100\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"101\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"103\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"105\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"106\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"107\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"109\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"111\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"113\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"114\" output=\"&#x0005;\"/>" << endl
				<< "            <key code=\"115\" output=\"&#x0001;\"/>" << endl
				<< "            <key code=\"116\" output=\"&#x000B;\"/>" << endl
				<< "            <key code=\"117\" output=\"&#x007F;\"/>" << endl
				<< "            <key code=\"118\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"119\" output=\"&#x0004;\"/>" << endl
				<< "            <key code=\"120\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"121\" output=\"&#x000C;\"/>" << endl
				<< "            <key code=\"122\" output=\"&#x0010;\"/>" << endl
				<< "            <key code=\"123\" output=\"&#x001C;\"/>" << endl
				<< "            <key code=\"124\" output=\"&#x001D;\"/>" << endl
				<< "            <key code=\"125\" output=\"&#x001F;\"/>" << endl
				<< "            <key code=\"126\" output=\"&#x001E;\"/>" << endl
				<< "        </keyMap>" << endl;

		}

		txt << "    </keyMapSet>" << endl
			<< "    <keyMapSet id=\"JIS\">" << endl
			<< "        <keyMap index=\"0\" baseMapSet=\"ANSI\" baseIndex=\"0\">" << endl
			<< "            <key code=\"512\" output=\"\"/>" << endl
			<< "        </keyMap>" << endl
			<< "        <keyMap index=\"1\" baseMapSet=\"ANSI\" baseIndex=\"1\">" << endl
			<< "            <key code=\"512\" output=\"\"/>" << endl
			<< "        </keyMap>" << endl
			<< "        <keyMap index=\"2\" baseMapSet=\"ANSI\" baseIndex=\"2\">" << endl
			<< "            <key code=\"512\" output=\"\"/>" << endl
			<< "        </keyMap>" << endl
			<< "        <keyMap index=\"3\" baseMapSet=\"ANSI\" baseIndex=\"3\">" << endl
			<< "            <key code=\"512\" output=\"\"/>" << endl
			<< "        </keyMap>" << endl
			<< "        <keyMap index=\"4\" baseMapSet=\"ANSI\" baseIndex=\"4\">" << endl
			<< "            <key code=\"512\" output=\"\"/>" << endl
			<< "        </keyMap>" << endl
			<< "        <keyMap index=\"5\" baseMapSet=\"ANSI\" baseIndex=\"5\">" << endl
			<< "            <key code=\"512\" output=\"\"/>" << endl
			<< "        </keyMap>" << endl
			<< "        <keyMap index=\"6\" baseMapSet=\"ANSI\" baseIndex=\"6\">" << endl
			<< "            <key code=\"512\" output=\"\"/>" << endl
			<< "        </keyMap>" << endl
			<< "    </keyMapSet>" << endl
			<< "</keyboard>" << endl;
	}
};

map<int, int> Exporter::mac_keys{
	{0, 13}, {1, 14}, {2, 15}, {3, 16}, {4, 18}, {5, 17}, {6, 24}, {7, 25}, {8, 26}, {9, 27},
	{11, 28}, {12, 0}, {13, 1}, {14, 2}, {15, 3}, {16, 5}, {17, 4}, {30, 11}, {31, 8},
	{32, 6}, {33, 10}, {34, 7}, {35, 9}, {37, 21}, {38, 19}, {39, 23}, {40, 20}, {41, 22},
	{43, 31}, {44, 33}, {45, 29}, {46, 30}, {47, 32}
};

map<char, string> Exporter::mac_upper{
	{'[', "{"}, {']', "}"}, {'\'',"&#x0022;"}, {';',":"}, {',',"&#x003C;"}, {'.',"&#x003E;"}, {'/',"?"}
};

map<char, string> Exporter::xmodmap_keys {
	{'q', "            q             Q       adiaeresis        Adiaeresis"},
	{'d', "            d             D   dead_diaeresis        asciitilde"},
	{'r', "            r             R       dead_grave        asciitilde"},
	{'w', "            w             W            aring             Aring"},
	{'b', "            b             B       dead_breve        asciitilde"},
	{'j', "            j             J          dstroke           Dstroke"},
	{'f', "            f             F           atilde            Atilde"},
	{'u', "            u             U           uacute            Uacute"},
	{'p', "            p             P           oslash          Ooblique"},
	{';', "    semicolon         colon       odiaeresis        Odiaeresis"},
	{'[', "  bracketleft     braceleft    guillemotleft             U2039"},
	{']', " bracketright    braceright   guillemotright             U203a"},
	{'\\',"    backslash           bar       asciitilde        asciitilde"},
	{'a', "            a             A           aacute            Aacute"},
	{'s', "            s             S           ssharp        asciitilde"},
	{'h', "            h             H       dead_caron        asciitilde"},
	{'t', "            t             T       dead_acute  dead_doubleacute"},
	{'g', "            g             G      dead_ogonek        asciitilde"},
	{'y', "            y             Y       udiaeresis        Udiaeresis"},
	{'n', "            n             N           ntilde            Ntilde"},
	{'e', "            e             E           eacute            Eacute"},
	{'o', "            o             O           oacute            Oacute"},
	{'i', "            i             I           iacute            Iacute"},
	{'\'',"   apostrophe      quotedbl           otilde            Otilde"},
	{'z', "            z             Z               ae                AE"},
	{'x', "            x             X  dead_circumflex        asciitilde"},
	{'m', "            m             M      dead_macron        asciitilde"},
	{'c', "            c             C         ccedilla          Ccedilla"},
	{'v', "            v             V               oe                OE"},
	{'k', "            k             K   dead_abovering        asciitilde"},
	{'l', "            l             L          lstroke           Lstroke"},
	{',', "        comma          less     dead_cedilla        asciitilde"},
	{'.', "       period       greater    dead_abovedot        asciitilde"},
	{'/', "        slash      question     questiondown        asciitilde"}
};

vector<string> Exporter::autohotkey_keys{
	"q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\",
	"a", "s", "d", "f", "g", "h", "j", "k", "l", "SC027", "'",
	"z", "x", "c", "v", "b", "n", "m", ",", ".", "/"
};

map<char, string> Exporter::klc_keys{
	{'q', "Q		1	q	Q	-1		// LATIN SMALL LETTER Q, LATIN CAPITAL LETTER Q, <none>"},
	{'d', "D		1	d	D	-1		// LATIN SMALL LETTER D, LATIN CAPITAL LETTER D, <none>"},
	{'r', "R		1	r	R	-1		// LATIN SMALL LETTER R, LATIN CAPITAL LETTER R, <none>"},
	{'w', "W		1	w	W	-1		// LATIN SMALL LETTER W, LATIN CAPITAL LETTER W, <none>"},
	{'b', "B		1	b	B	-1		// LATIN SMALL LETTER B, LATIN CAPITAL LETTER B, <none>"},
	{'j', "J		1	j	J	-1		// LATIN SMALL LETTER J, LATIN CAPITAL LETTER J, <none>"},
	{'f', "F		1	f	F	-1		// LATIN SMALL LETTER F, LATIN CAPITAL LETTER F, <none>"},
	{'u', "U		1	u	U	-1		// LATIN SMALL LETTER U, LATIN CAPITAL LETTER U, <none>"},
	{'p', "P		1	p	P	-1		// LATIN SMALL LETTER P, LATIN CAPITAL LETTER P, <none>"},
	{';', "OEM_1		0	003b	003a	-1		// SEMICOLON, COLON, <none>"},
	{'[', "OEM_4		0	005b	007b	001b		// LEFT SQUARE BRACKET, LEFT CURLY BRACKET, ESCAPE"},
	{']', "OEM_6		0	005d	007d	001d		// RIGHT SQUARE BRACKET, RIGHT CURLY BRACKET, INFORMATION SEPARATOR THREE"},
	{'a', "A		1	a	A	-1		// LATIN SMALL LETTER A, LATIN CAPITAL LETTER A, <none>"},
	{'s', "S		1	s	S	-1		// LATIN SMALL LETTER S, LATIN CAPITAL LETTER S, <none>"},
	{'h', "H		1	h	H	-1		// LATIN SMALL LETTER H, LATIN CAPITAL LETTER H, <none>"},
	{'t', "T		1	t	T	-1		// LATIN SMALL LETTER T, LATIN CAPITAL LETTER T, <none>"},
	{'g', "G		1	g	G	-1		// LATIN SMALL LETTER G, LATIN CAPITAL LETTER G, <none>"},
	{'y', "Y		1	y	Y	-1		// LATIN SMALL LETTER Y, LATIN CAPITAL LETTER Y, <none>"},
	{'n', "N		1	n	N	-1		// LATIN SMALL LETTER N, LATIN CAPITAL LETTER N, <none>"},
	{'e', "E		1	e	E	-1		// LATIN SMALL LETTER E, LATIN CAPITAL LETTER E, <none>"},
	{'o', "O		1	o	O	-1		// LATIN SMALL LETTER O, LATIN CAPITAL LETTER O, <none>"},
	{'i', "I		1	i	I	-1		// LATIN SMALL LETTER I, LATIN CAPITAL LETTER I, <none>"},
	{'\'',"OEM_7		0	0027	0022	-1		// APOSTROPHE, QUOTATION MARK, <none>"},
	{'z', "Z		1	z	Z	-1		// LATIN SMALL LETTER Z, LATIN CAPITAL LETTER Z, <none>"},
	{'x', "X		1	x	X	-1		// LATIN SMALL LETTER X, LATIN CAPITAL LETTER X, <none>"},
	{'m', "M		1	m	M	-1		// LATIN SMALL LETTER M, LATIN CAPITAL LETTER M, <none>"},
	{'c', "C		1	c	C	-1		// LATIN SMALL LETTER C, LATIN CAPITAL LETTER C, <none>"},
	{'v', "V		1	v	V	-1		// LATIN SMALL LETTER V, LATIN CAPITAL LETTER V, <none>"},
	{'k', "K		1	k	K	-1		// LATIN SMALL LETTER K, LATIN CAPITAL LETTER K, <none>"},
	{'l', "L		1	l	L	-1		// LATIN SMALL LETTER L, LATIN CAPITAL LETTER L, <none>"},
	{',', "OEM_COMMA	0	002c	003c	-1		// COMMA, LESS-THAN SIGN, <none>"},
	{'.', "OEM_PERIOD	0	002e	003e	-1		// FULL STOP, GREATER-THAN SIGN, <none>"},
	{'/', "OEM_2		0	002f	003f	-1		// SOLIDUS, QUESTION MARK, <none>"}
};

#endif