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
		/*
		wxFFileOutputStream out(title + ".zip");
		wxZipOutputStream zip(out);

		Export_xmodmap();
		zip.PutNextEntry("xmodmap." + title);

		zip.Close();
		*/
	}

	void Export_xmodmap(wxTextOutputStream& txt) {
		txt << "! xmodmap for the " + title + " layout" << endl << endl
			<< "keycode  49 = grave    asciitilde       dead_tilde        asciitilde" << endl
			<< "keycode  10 = 1        exclam       exclamdown       onesuperior" << endl
			<< "keycode  11 = 2            at        masculine       twosuperior" << endl
			<< "keycode  12 = 3    numbersign      ordfeminine     threesuperior" << endl
			<< "keycode  13 = 4        dollar             cent          sterling" << endl
			<< "keycode  14 = 5       percent         EuroSign               yen" << endl
			<< "keycode  15 = 6   asciicircum          hstroke           Hstroke" << endl
			<< "keycode  16 = 7     ampersand              eth               ETH" << endl
			<< "keycode  17 = 8      asterisk            thorn             THORN" << endl
			<< "keycode  18 = 9     parenleft   leftsinglequotemark   leftdoublequotemark" << endl
			<< "keycode  19 = 0    parenright  rightsinglequotemark   rightdoublequotemark" << endl
			<< "keycode  20 = minus    underscore           endash            emdash" << endl
			<< "keycode  21 = equal          plus         multiply          division" << endl << endl;

		map<char, string>::iterator xmodmap_key;
		for (int i = 0; i < keys.size(); i++)
		{
			xmodmap_key = xmodmap_keys.find(keys[i]->GetLabel().c_str()[0]);
			if (xmodmap_key != xmodmap_keys.end())
			{
				txt << "keycode  " << keys[i]->GetId() << " =" << xmodmap_key->second << endl;
			}
		}
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
	{'x', "            x             X  dead_circumflex        asciitild"},
	{'m', "            m             M      dead_macron        asciitilde"},
	{'c', "            c             C         ccedilla          Ccedilla"},
	{'v', "            v             V               oe                OE"},
	{'k', "            k             K   dead_abovering        asciitilde"},
	{'l', "            l             L          lstroke           Lstroke"},
	{',', "        comma          less     dead_cedilla        asciitilde"},
	{'.', "       period       greater    dead_abovedot        asciitilde"},
	{'/', "        slash      question     questiondown        asciitilde"}
};
/*                                                                                   
keycode  66 =    BackSpace        Escape        BackSpace         BackSpace            
keycode  94 =        minus    underscore           endash            emdash            
keycode  65 =        space         space            space      nobreakspace            
keycode 113 =  Mode_switch   Mode_switch                                               
clear Lock
*/
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