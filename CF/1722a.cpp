#include <iostream>
using namespace std;

string arr[120] = {
"Timur",
"Timru",
"Tiumr",
"Tiurm",
"Tirum",
"Tirmu",
"Tmiur",
"Tmiru",
"Tmuir",
"Tmuri",
"Tmrui",
"Tmriu",
"Tumir",
"Tumri",
"Tuimr",
"Tuirm",
"Turim",
"Turmi",
"Trmui",
"Trmiu",
"Trumi",
"Truim",
"Trium",
"Trimu",
"iTmur",
"iTmru",
"iTumr",
"iTurm",
"iTrum",
"iTrmu",
"imTur",
"imTru",
"imuTr",
"imurT",
"imruT",
"imrTu",
"iumTr",
"iumrT",
"iuTmr",
"iuTrm",
"iurTm",
"iurmT",
"irmuT",
"irmTu",
"irumT",
"iruTm",
"irTum",
"irTmu",
"miTur",
"miTru",
"miuTr",
"miurT",
"miruT",
"mirTu",
"mTiur",
"mTiru",
"mTuir",
"mTuri",
"mTrui",
"mTriu",
"muTir",
"muTri",
"muiTr",
"muirT",
"muriT",
"murTi",
"mrTui",
"mrTiu",
"mruTi",
"mruiT",
"mriuT",
"mriTu",
"uimTr",
"uimrT",
"uiTmr",
"uiTrm",
"uirTm",
"uirmT",
"umiTr",
"umirT",
"umTir",
"umTri",
"umrTi",
"umriT",
"uTmir",
"uTmri",
"uTimr",
"uTirm",
"uTrim",
"uTrmi",
"urmTi",
"urmiT",
"urTmi",
"urTim",
"uriTm",
"urimT",
"rimuT",
"rimTu",
"riumT",
"riuTm",
"riTum",
"riTmu",
"rmiuT",
"rmiTu",
"rmuiT",
"rmuTi",
"rmTui",
"rmTiu",
"rumiT",
"rumTi",
"ruimT",
"ruiTm",
"ruTim",
"ruTmi",
"rTmui",
"rTmiu",
"rTumi",
"rTuim",
"rTium",
"rTimu",
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if (n != 5) {
            cout << "NO" << '\n';
            continue;
        }

        bool flag = false;
        for (string name : arr) {
            if (s == name) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}