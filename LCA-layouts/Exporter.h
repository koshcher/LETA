#ifndef EXPORTER_H
#define EXPORTER_H

#include <string>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include <fstream>
#include <vector>

using namespace std;

class Exporter
{
private:
	vector<vector<wxButton*>> keys;
	string title;

public:
	Exporter(const string& title, vector<vector<wxButton*>>& keys) {
		this->title = title;
		this->keys = keys;
	}

	void Export() {
		wxFFileOutputStream out(title + ".zip");
		wxZipOutputStream zip(out);

		zip.PutNextEntry("xmodmap." + title);
		Export_xmodmap();

		zip.Close();
	}

	void Export_xmodmap() {
		ofstream f(title + ".zip/xmodmap." + title);
		if (f.is_open()) {

			f << "! xmodmap for the " + title + " layout";

			for (int i = 0; i < keys.size(); i++) {
				for (int j = 0; j < keys[i].size(); j++) {

				}
			}

			f.close();
		}
	}
};

#endif