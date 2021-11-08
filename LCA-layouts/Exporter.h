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

#endif