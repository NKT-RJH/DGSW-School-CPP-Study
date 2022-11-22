#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#define YEAR2MONTH 12
#define HUNDRED 100
#define TEN 10
#define ONE 1
#define COMPUTERSTARTYEAR 1900

namespace Tools
{
	template <typename T>
	static T Input(const char* question)
	{
		T storage = NULL;

		while (true)
		{
			cout << question;

			cin >> storage;

			if (!cin.fail()) break;

			cin.clear();
			cin.ignore();
			system("cls");
		}

		return storage;
	}

	template<typename Key, typename Value>
	struct KeyValuePair
	{
		Key key;
		Value value;
	};
}

namespace IncomeTaxManager
{
	typedef struct TableStruct
	{
		int start;
		int end;
		int tax;
	} Table;

	Table table[] = {
{770, 775, 0},
{775, 780, 0},
{780, 785, 0},
{785, 790, 0},
{790, 795, 0},
{795, 800, 0},
{800, 805, 0},
{805, 810, 0},
{810, 815, 0},
{815, 820, 0},
{820, 825, 0},
{825, 830, 0},
{830, 835, 0},
{835, 840, 0},
{840, 845, 0},
{845, 850, 0},
{850, 855, 0},
{855, 860, 0},
{860, 865, 0},
{865, 870, 0},
{870, 875, 0},
{875, 880, 0},
{880, 885, 0},
{885, 890, 0},
{890, 895, 0},
{895, 900, 0},
{900, 905, 0},
{905, 910, 0},
{910, 915, 0},
{915, 920, 0},
{920, 925, 0},
{925, 930, 0},
{930, 935, 0},
{935, 940, 0},
{940, 945, 0},
{945, 950, 0},
{950, 955, 0},
{955, 960, 0},
{960, 965, 0},
{965, 970, 0},
{970, 975, 0},
{975, 980, 0},
{980, 985, 0},
{985, 990, 0},
{990, 995, 0},
{995, 1000, 0},
{1000, 1005, 0},
{1005, 1010, 0},
{1010, 1015, 0},
{1015, 1020, 0},
{1020, 1025, 0},
{1025, 1030, 0},
{1030, 1035, 0},
{1035, 1040, 0},
{1040, 1045, 0},
{1045, 1050, 0},
{1050, 1055, 0},
{1055, 1060, 0},
{1060, 1065, 1040},
{1065, 1070, 1110},
{1070, 1075, 1180},
{1075, 1080, 1250},
{1080, 1085, 1320},
{1085, 1090, 1390},
{1090, 1095, 1460},
{1095, 1100, 1530},
{1100, 1105, 1600},
{1105, 1110, 1670},
{1110, 1115, 1740},
{1115, 1120, 1810},
{1120, 1125, 1880},
{1125, 1130, 1950},
{1130, 1135, 2020},
{1135, 1140, 2090},
{1140, 1145, 2160},
{1145, 1150, 2230},
{1150, 1155, 2300},
{1155, 1160, 2370},
{1160, 1165, 2440},
{1165, 1170, 2500},
{1170, 1175, 2570},
{1175, 1180, 2640},
{1180, 1185, 2710},
{1185, 1190, 2780},
{1190, 1195, 2850},
{1195, 1200, 2920},
{1200, 1205, 2990},
{1205, 1210, 3060},
{1210, 1215, 3130},
{1215, 1220, 3200},
{1220, 1225, 3270},
{1225, 1230, 3340},
{1230, 1235, 3410},
{1235, 1240, 3480},
{1240, 1245, 3550},
{1245, 1250, 3620},
{1250, 1255, 3700},
{1255, 1260, 3810},
{1260, 1265, 3910},
{1265, 1270, 4010},
{1270, 1275, 4120},
{1275, 1280, 4220},
{1280, 1285, 4320},
{1285, 1290, 4430},
{1290, 1295, 4530},
{1295, 1300, 4630},
{1300, 1305, 4740},
{1305, 1310, 4840},
{1310, 1315, 4940},
{1315, 1320, 5050},
{1320, 1325, 5150},
{1325, 1330, 5250},
{1330, 1335, 5360},
{1335, 1340, 5460},
{1340, 1345, 5560},
{1345, 1350, 5670},
{1350, 1355, 5770},
{1355, 1360, 5870},
{1360, 1365, 5980},
{1365, 1370, 6080},
{1370, 1375, 6180},
{1375, 1380, 6290},
{1380, 1385, 6390},
{1385, 1390, 6490},
{1390, 1395, 6600},
{1395, 1400, 6700},
{1400, 1405, 6800},
{1405, 1410, 6910},
{1410, 1415, 7010},
{1415, 1420, 7110},
{1420, 1425, 7210},
{1425, 1430, 7320},
{1430, 1435, 7420},
{1435, 1440, 7520},
{1440, 1445, 7630},
{1445, 1450, 7730},
{1450, 1455, 7830},
{1455, 1460, 7940},
{1460, 1465, 8040},
{1465, 1470, 8140},
{1470, 1475, 8250},
{1475, 1480, 8350},
{1480, 1485, 8450},
{1485, 1490, 8560},
{1490, 1495, 8660},
{1495, 1500, 8760},
{1500, 1510, 8920},
{1510, 1520, 9120},
{1520, 1530, 9330},
{1530, 1540, 9540},
{1540, 1550, 9740},
{1550, 1560, 9950},
{1560, 1570, 10160},
{1570, 1580, 10360},
{1580, 1590, 10570},
{1590, 1600, 10780},
{1600, 1610, 10980},
{1610, 1620, 11190},
{1620, 1630, 11400},
{1630, 1640, 11600},
{1640, 1650, 11810},
{1650, 1660, 12020},
{1660, 1670, 12220},
{1670, 1680, 12430},
{1680, 1690, 12640},
{1690, 1700, 12840},
{1700, 1710, 13050},
{1710, 1720, 13260},
{1720, 1730, 13460},
{1730, 1740, 13670},
{1740, 1750, 13880},
{1750, 1760, 14080},
{1760, 1770, 14290},
{1770, 1780, 14500},
{1780, 1790, 14700},
{1790, 1800, 14910},
{1800, 1810, 15110},
{1810, 1820, 15320},
{1820, 1830, 15530},
{1830, 1840, 15730},
{1840, 1850, 15940},
{1850, 1860, 16150},
{1860, 1870, 16350},
{1870, 1880, 16560},
{1880, 1890, 16770},
{1890, 1900, 16970},
{1900, 1910, 17180},
{1910, 1920, 17390},
{1920, 1930, 17590},
{1930, 1940, 17800},
{1940, 1950, 18010},
{1950, 1960, 18210},
{1960, 1970, 18420},
{1970, 1980, 18630},
{1980, 1990, 18880},
{1990, 2000, 19200},
{2000, 2010, 19520},
{2010, 2020, 19850},
{2020, 2030, 20170},
{2030, 2040, 20490},
{2040, 2050, 20810},
{2050, 2060, 21130},
{2060, 2070, 21450},
{2070, 2080, 21770},
{2080, 2090, 22090},
{2090, 2100, 22420},
{2100, 2110, 22740},
{2110, 2120, 23060},
{2120, 2130, 23380},
{2130, 2140, 23700},
{2140, 2150, 24020},
{2150, 2160, 24340},
{2160, 2170, 24660},
{2170, 2180, 24990},
{2180, 2190, 25310},
{2190, 2200, 25630},
{2200, 2210, 25950},
{2210, 2220, 26270},
{2220, 2230, 26590},
{2230, 2240, 26910},
{2240, 2250, 27240},
{2250, 2260, 27560},
{2260, 2270, 27880},
{2270, 2280, 28200},
{2280, 2290, 28520},
{2290, 2300, 28840},
{2300, 2310, 29160},
{2310, 2320, 29480},
{2320, 2330, 29810},
{2330, 2340, 30130},
{2340, 2350, 30450},
{2350, 2360, 30770},
{2360, 2370, 31090},
{2370, 2380, 31410},
{2380, 2390, 31970},
{2390, 2400, 32770},
{2400, 2410, 33570},
{2410, 2420, 34380},
{2420, 2430, 35180},
{2430, 2440, 35980},
{2440, 2450, 36790},
{2450, 2460, 37590},
{2460, 2470, 38390},
{2470, 2480, 39200},
{2480, 2490, 40000},
{2490, 2500, 40800},
{2500, 2510, 41630},
{2510, 2520, 42490},
{2520, 2530, 43340},
{2530, 2540, 44200},
{2540, 2550, 45050},
{2550, 2560, 45910},
{2560, 2570, 46770},
{2570, 2580, 47620},
{2580, 2590, 48480},
{2590, 2600, 49330},
{2600, 2610, 50190},
{2610, 2620, 51040},
{2620, 2630, 51900},
{2630, 2640, 52760},
{2640, 2650, 53610},
{2650, 2660, 54470},
{2660, 2670, 55320},
{2670, 2680, 56180},
{2680, 2690, 57040},
{2690, 2700, 57890},
{2700, 2710, 58750},
{2710, 2720, 59600},
{2720, 2730, 60460},
{2730, 2740, 61310},
{2740, 2750, 62170},
{2750, 2760, 63030},
{2760, 2770, 63880},
{2770, 2780, 64740},
{2780, 2790, 65590},
{2790, 2800, 66450},
{2800, 2810, 67300},
{2810, 2820, 68160},
{2820, 2830, 69020},
{2830, 2840, 69870},
{2840, 2850, 70730},
{2850, 2860, 71580},
{2860, 2870, 72440},
{2870, 2880, 73290},
{2880, 2890, 74150},
{2890, 2900, 75010},
{2900, 2910, 75860},
{2910, 2920, 76720},
{2920, 2930, 77570},
{2930, 2940, 78430},
{2940, 2950, 79280},
{2950, 2960, 80140},
{2960, 2970, 81000},
{2970, 2980, 81850},
{2980, 2990, 82710},
{2990, 3000, 83560},
{3000, 3020, 84850},
{3020, 3040, 86560},
{3040, 3060, 88270},
{3060, 3080, 89980},
{3080, 3100, 91690},
{3100, 3120, 93400},
{3120, 3140, 95760},
{3140, 3160, 98210},
{3160, 3180, 100650},
{3180, 3200, 103100},
{3200, 3220, 105540},
{3220, 3240, 107990},
{3240, 3260, 110430},
{3260, 3280, 112880},
{3280, 3300, 115320},
{3300, 3320, 117770},
{3320, 3340, 120210},
{3340, 3360, 122660},
{3360, 3380, 125100},
{3380, 3400, 127550},
{3400, 3420, 129990},
{3420, 3440, 132440},
{3440, 3460, 134880},
{3460, 3480, 137330},
{3480, 3500, 139770},
{3500, 3520, 142220},
{3520, 3540, 144660},
{3540, 3560, 147110},
{3560, 3580, 149550},
{3580, 3600, 152000},
{3600, 3620, 154440},
{3620, 3640, 156890},
{3640, 3660, 159330},
{3660, 3680, 161780},
{3680, 3700, 164220},
{3700, 3720, 166670},
{3720, 3740, 169110},
{3740, 3760, 171560},
{3760, 3780, 178920},
{3780, 3800, 181590},
{3800, 3820, 184260},
{3820, 3840, 186930},
{3840, 3860, 189600},
{3860, 3880, 192270},
{3880, 3900, 194940},
{3900, 3920, 197610},
{3920, 3940, 200280},
{3940, 3960, 202950},
{3960, 3980, 205620},
{3980, 4000, 208290},
{4000, 4020, 210960},
{4020, 4040, 213630},
{4040, 4060, 216300},
{4060, 4080, 218970},
{4080, 4100, 221640},
{4100, 4120, 224310},
{4120, 4140, 226980},
{4140, 4160, 229650},
{4160, 4180, 232320},
{4180, 4200, 234990},
{4200, 4220, 237660},
{4220, 4240, 240330},
{4240, 4260, 243000},
{4260, 4280, 245670},
{4280, 4300, 248340},
{4300, 4320, 251010},
{4320, 4340, 253680},
{4340, 4360, 256350},
{4360, 4380, 259020},
{4380, 4400, 261690},
{4400, 4420, 264360},
{4420, 4440, 267030},
{4440, 4460, 269700},
{4460, 4480, 272370},
{4480, 4500, 275040},
{4500, 4520, 277840},
{4520, 4540, 280650},
{4540, 4560, 283450},
{4560, 4580, 286260},
{4580, 4600, 291560},
{4600, 4620, 294370},
{4620, 4640, 297170},
{4640, 4660, 299980},
{4660, 4680, 302780},
{4680, 4700, 305590},
{4700, 4720, 308390},
{4720, 4740, 311200},
{4740, 4760, 314000},
{4760, 4780, 316810},
{4780, 4800, 319610},
{4800, 4820, 322420},
{4820, 4840, 325220},
{4840, 4860, 328030},
{4860, 4880, 330830},
{4880, 4900, 333640},
{4900, 4920, 336440},
{4920, 4940, 339250},
{4940, 4960, 342050},
{4960, 4980, 344860},
{4980, 5000, 347660},
{5000, 5020, 350470},
{5020, 5040, 353270},
{5040, 5060, 356080},
{5060, 5080, 358880},
{5080, 5100, 361690},
{5100, 5120, 364490},
{5120, 5140, 367300},
{5140, 5160, 370100},
{5160, 5180, 372910},
{5180, 5200, 375710},
{5200, 5220, 378520},
{5220, 5240, 381320},
{5240, 5260, 384130},
{5260, 5280, 386930},
{5280, 5300, 389740},
{5300, 5320, 392540},
{5320, 5340, 395350},
{5340, 5360, 398150},
{5360, 5380, 400960},
{5380, 5400, 403760},
{5400, 5420, 406570},
{5420, 5440, 409370},
{5440, 5460, 412180},
{5460, 5480, 414980},
{5480, 5500, 417790},
{5500, 5520, 420590},
{5520, 5540, 423400},
{5540, 5560, 426200},
{5560, 5580, 429010},
{5580, 5600, 431810},
{5600, 5620, 435890},
{5620, 5640, 440380},
{5640, 5660, 444860},
{5660, 5680, 449350},
{5680, 5700, 453840},
{5700, 5720, 458330},
{5720, 5740, 462820},
{5740, 5760, 467300},
{5760, 5780, 471790},
{5780, 5800, 476280},
{5800, 5820, 480770},
{5820, 5840, 485260},
{5840, 5860, 512120},
{5860, 5880, 519150},
{5880, 5900, 523690},
{5900, 5920, 528220},
{5920, 5940, 532760},
{5940, 5960, 537300},
{5960, 5980, 541830},
{5980, 6000, 546370},
{6000, 6020, 550900},
{6020, 6040, 555440},
{6040, 6060, 559980},
{6060, 6080, 564510},
{6080, 6100, 569050},
{6100, 6120, 573580},
{6120, 6140, 578120},
{6140, 6160, 582660},
{6160, 6180, 587190},
{6180, 6200, 591730},
{6200, 6220, 596260},
{6220, 6240, 600800},
{6240, 6260, 605340},
{6260, 6280, 609870},
{6280, 6300, 614410},
{6300, 6320, 618940},
{6320, 6340, 623480},
{6340, 6360, 628020},
{6360, 6380, 632550},
{6380, 6400, 637090},
{6400, 6420, 641620},
{6420, 6440, 646160},
{6440, 6460, 650700},
{6460, 6480, 655230},
{6480, 6500, 659770},
{6500, 6520, 664300},
{6520, 6540, 668840},
{6540, 6560, 673380},
{6560, 6580, 677910},
{6580, 6600, 682450},
{6600, 6620, 686980},
{6620, 6640, 691520},
{6640, 6660, 696060},
{6660, 6680, 700590},
{6680, 6700, 705130},
{6700, 6720, 709660},
{6720, 6740, 714200},
{6740, 6760, 718740},
{6760, 6780, 723270},
{6780, 6800, 727810},
{6800, 6820, 732340},
{6820, 6840, 736880},
{6840, 6860, 741420},
{6860, 6880, 745950},
{6880, 6900, 750490},
{6900, 6920, 755020},
{6920, 6940, 759560},
{6940, 6960, 764100},
{6960, 6980, 768630},
{6980, 7000, 773170},
{7000, 7020, 777700},
{7020, 7040, 782240},
{7040, 7060, 786780},
{7060, 7080, 791310},
{7080, 7100, 795850},
{7100, 7120, 800380},
{7120, 7140, 804920},
{7140, 7160, 809460},
{7160, 7180, 813990},
{7180, 7200, 818530},
{7200, 7220, 823060},
{7220, 7240, 827600},
{7240, 7260, 832140},
{7260, 7280, 836670},
{7280, 7300, 841210},
{7300, 7320, 845740},
{7320, 7340, 850280},
{7340, 7360, 854820},
{7360, 7380, 859350},
{7380, 7400, 863890},
{7400, 7420, 868420},
{7420, 7440, 872960},
{7440, 7460, 877500},
{7460, 7480, 882030},
{7480, 7500, 886570},
{7500, 7520, 891100},
{7520, 7540, 895640},
{7540, 7560, 900180},
{7560, 7580, 904710},
{7580, 7600, 909250},
{7600, 7620, 913780},
{7620, 7640, 918320},
{7640, 7660, 922860},
{7660, 7680, 927390},
{7680, 7700, 931930},
{7700, 7720, 936460},
{7720, 7740, 941000},
{7740, 7760, 945540},
{7760, 7780, 950070},
{7780, 7800, 954610},
{7800, 7820, 959140},
{7820, 7840, 963680},
{7840, 7860, 968220},
{7860, 7880, 972750},
{7880, 7900, 977290},
{7900, 7920, 981820},
{7920, 7940, 986360},
{7940, 7960, 990900},
{7960, 7980, 995430},
{7980, 8000, 999970},
{8000, 8020, 1004500},
{8020, 8040, 1009040},
{8040, 8060, 1013580},
{8060, 8080, 1018110},
{8080, 8100, 1022650},
{8100, 8120, 1027180},
{8120, 8140, 1031720},
{8140, 8160, 1036260},
{8160, 8180, 1040790},
{8180, 8200, 1045330},
{8200, 8220, 1049860},
{8220, 8240, 1054400},
{8240, 8260, 1058940},
{8260, 8280, 1063470},
{8280, 8300, 1068010},
{8300, 8320, 1072540},
{8320, 8340, 1077080},
{8340, 8360, 1081740},
{8360, 8380, 1086420},
{8380, 8400, 1091100},
{8400, 8420, 1095780},
{8420, 8440, 1100460},
{8440, 8460, 1105140},
{8460, 8480, 1109820},
{8480, 8500, 1114500},
{8500, 8520, 1119180},
{8520, 8540, 1123860},
{8540, 8560, 1128540},
{8560, 8580, 1133220},
{8580, 8600, 1137900},
{8600, 8620, 1142580},
{8620, 8640, 1147260},
{8640, 8660, 1151940},
{8660, 8680, 1156620},
{8680, 8700, 1161300},
{8700, 8720, 1165980},
{8720, 8740, 1170660},
{8740, 8760, 1175340},
{8760, 8780, 1180020},
{8780, 8800, 1184700},
{8800, 8820, 1189380},
{8820, 8840, 1194060},
{8840, 8860, 1198740},
{8860, 8880, 1203420},
{8880, 8900, 1208100},
{8900, 8920, 1212780},
{8920, 8940, 1217460},
{8940, 8960, 1222140},
{8960, 8980, 1226820},
{8980, 9000, 1231500},
{9000, 9020, 1236180},
{9020, 9040, 1240860},
{9040, 9060, 1245540},
{9060, 9080, 1250220},
{9080, 9100, 1254900},
{9100, 9120, 1259580},
{9120, 9140, 1264260},
{9140, 9160, 1268940},
{9160, 9180, 1273620},
{9180, 9200, 1278300},
{9200, 9220, 1282980},
{9220, 9240, 1289640},
{9240, 9260, 1296470},
{9260, 9280, 1303290},
{9280, 9300, 1310120},
{9300, 9320, 1316940},
{9320, 9340, 1323770},
{9340, 9360, 1330590},
{9360, 9380, 1337420},
{9380, 9400, 1344240},
{9400, 9420, 1351070},
{9420, 9440, 1357890},
{9440, 9460, 1364720},
{9460, 9480, 1371540},
{9480, 9500, 1378370},
{9500, 9520, 1385190},
{9520, 9540, 1392020},
{9540, 9560, 1398840},
{9560, 9580, 1405670},
{9580, 9600, 1412490},
{9600, 9620, 1419320},
{9620, 9640, 1426140},
{9640, 9660, 1432970},
{9660, 9680, 1439790},
{9680, 9700, 1446620},
{9700, 9720, 1453440},
{9720, 9740, 1460270},
{9740, 9760, 1467090},
{9760, 9780, 1473920},
{9780, 9800, 1480740},
{9800, 9820, 1487570},
{9820, 9840, 1494390},
{9840, 9860, 1501220},
{9860, 9880, 1508040},
{9880, 9900, 1514870},
{9900, 9920, 1521690},
{9920, 9940, 1528520},
{9940, 9960, 1535340},
{9960, 9980, 1542170},
{9980, 10000, 1548990}
	};

	class IncomeTax
	{
	public:
		IncomeTax() = default;

		int Calcurate(int wages)
		{
			int tableSize = sizeof(table);

			int result = -1;

			for (int count = 0; count < tableSize; count++)
			{
				if (table[count].start * 10000 <= wages && table[count].end * 10000 > wages)
				{
					result = table[count].tax;
					break;
				}
			}
			
			this->result = result;
			//printf("%d\n\n\n", result);
			return result;
		}

		int GetResult() const
		{
			return result;
		}

	private:
		int result = 0;
	};
}

class SavingMoney
{
public:
	SavingMoney() = default;

	SavingMoney(int id, int year, double money, double interest, double tax)
		: id(id), year(year), money(money), interest(interest), tax(tax) {}

	virtual double Calcurate() = 0;

	void SetID(int value)
	{
		id = value;
	}
	void SetYear(int value)
	{
		year = value;
	}
	void SetMoney(double value)
	{
		money = value;
	}
	void SetInterest(double value)
	{
		interest = value;
	}
	void SetTax(double value)
	{
		tax = value;
	}

	int GetID() const
	{
		return id;
	}
	int GetYear() const
	{
		return year;
	}
	double GetMoney() const
	{
		return money;
	}
	double GetInterest() const
	{
		return interest;
	}
	double GetTax() const
	{
		return tax;
	}

protected:
	int id = -1;
	int year = 0;
	double money = 0;
	double interest = 0;
	double tax = 15.4;
};

class Deposit : public SavingMoney // 정기 예금
{
public:
	Deposit() = default;

	Deposit(int id, double money, int year, double interest, double tax)
		: SavingMoney(id, money, year, interest, tax) {}

	Deposit operator=(const Deposit& object)
	{
		id = object.id;
		year = object.year;
		money = object.money;
		interest = object.interest;
		tax = object.tax;

		return *this;
	}

	double Calcurate() override
	{
		double interestAddTax = money * year * interest / HUNDRED * (1 - tax / HUNDRED);
		double result = money + interestAddTax;

		return result;
	}

private:
	static const int formulaConstant = 1;
};

class Savings : public SavingMoney // 정기 적금
{
public:
	Savings() = default;

	Savings(int id, int year, double money, double interest, double tax)
		: SavingMoney(id, year, money, interest, tax) {}

	Savings operator=(const Savings& object)
	{
		id = object.id;
		year = object.year;
		money = object.money;
		interest = object.interest;
		tax = object.tax;

		return *this;
	}

	double Calcurate() override
	{
		double month = (double)year * YEAR2MONTH;

		double totalMoney = money * month;

		double interestAddTax = (interest * ((double)month + (double)formulaConstant1) / (double)formulaConstant2) * ((double)formulaConstant3 - tax / HUNDRED);

		double result = totalMoney * ((double)formulaConstant4 + interestAddTax / HUNDRED);
		
		return result;
	}

private:
	static const int formulaConstant1 = 1;
	static const int formulaConstant2 = 24;
	static const int formulaConstant3 = 1;
	static const int formulaConstant4 = 1;
};

class Account
{
public:
	Account() = default;

	Account(int id, string name, double annualSalary, double rateOfSalaryIncrease, double amountConsumed)
		: id(id), name(name), annualSalary(annualSalary), rateOfSalaryIncrease(rateOfSalaryIncrease), amountConsumed(amountConsumed)
	{
		salary = annualSalary / YEAR2MONTH;
	}
	Account(int id, string name, double annualSalary, double rateOfSalaryIncrease, double amountConsumed, Savings savings)
		: id(id), name(name), annualSalary(annualSalary), rateOfSalaryIncrease(rateOfSalaryIncrease), amountConsumed(amountConsumed), savings(savings)
	{
		salary = annualSalary / YEAR2MONTH;
	}
	Account(int id, string name, double annualSalary, double rateOfSalaryIncrease, double amountConsumed, Deposit deposit)
		: id(id), name(name), annualSalary(annualSalary), rateOfSalaryIncrease(rateOfSalaryIncrease), amountConsumed(amountConsumed), deposit(deposit)
	{
		salary = annualSalary / YEAR2MONTH;
	}
	Account(int id, string name, double annualSalary, double rateOfSalaryIncrease, double amountConsumed, Savings savings, Deposit deposit)
		: id(id), name(name), annualSalary(annualSalary), rateOfSalaryIncrease(rateOfSalaryIncrease), amountConsumed(amountConsumed), savings(savings), deposit(deposit)
	{
		salary = annualSalary / YEAR2MONTH;
	}

	void AYearLater()
	{
		annualSalary *= ONE + rateOfSalaryIncrease / HUNDRED;
		salary = annualSalary / YEAR2MONTH;
	}

	bool HasSavings() const
	{
		return id == savings.GetID();
	}
	bool HasDeposit() const
	{
		return id == deposit.GetID();
	}

	void SetID(int value)
	{
		if (value < 0) return;

		id = value;
	}
	void SetName(string value)
	{
		name = value;
	}
	void SetAnnualSalary(double value)
	{
		annualSalary = value;
		salary = value / YEAR2MONTH;
	}
	void SetRateOfSalaryIncrease(double value)
	{
		rateOfSalaryIncrease = value;
	}
	void SetAmountConsumed(double value)
	{
		amountConsumed = value;
	}
	void SetSavings(Savings value)
	{
		savings = value;
	}
	void SetDeposit(Deposit value)
	{
		deposit = value;
	}

	int GetID() const
	{
		return id;
	}
	string GetName() const
	{
		return name;
	}
	double GetSalary() const
	{
		return salary;
	}
	double GetAnnualSalary() const
	{
		return annualSalary;
	}
	double GetAmountConsumed() const
	{
		return amountConsumed;
	}
	Savings GetSavings() const
	{
		return savings;
	}
	Deposit GetDeposit() const
	{
		return deposit;
	}

private:
	int id = 0;
	string name;
	double annualSalary = 0;
	double salary = 0;
	double rateOfSalaryIncrease = 0;
	double amountConsumed = 0;
	Savings savings;
	Deposit deposit;
};

class Bank
{
public:
	Bank()
	{
		accounts.resize(0);
	}
	Bank(vector<Account> values)
	{
		accounts = values;
	}

	void AddAccount(Account account)
	{
		if (OverlapCheck(account)) return;

		accounts.push_back(account);
	}
	void RemoveAccount(int id)
	{
		int count = 0;
		
		for (; count < accounts.size(); count++)
		{
			if (accounts[count].GetID() == id) break;
		}

		accounts.erase(accounts.begin() + count);
	}

	Account GetAccount(int number)
	{
		if (accounts.empty()) throw exception();

		if (number >= accounts.size() && number < 0) throw out_of_range(NULL);
	
		return accounts[number];
	}

private:
	vector<Account> accounts;

	bool OverlapCheck(Account value)
	{
		int check = 0;

		for (int count = 0; count < accounts.size(); count++)
		{
			if (accounts[count].GetID() == value.GetID())
			{
				check++;
			}
		}

		return check > 0;
	}
};

class Insurance
{
public:
	Insurance() = default;

	Insurance(string name, double rate)
		: name(name), rate(rate) {}

	void SetName(string value)
	{
		name = value;
	}
	void SetRate(double value)
	{
		rate = value;
	}

	string GetName() const
	{
		return name;
	}
	double GetRate() const
	{
		return rate;
	}

	double Calcurate(double value)
	{
		return value * rate / percentage;
	}

private:
	string name;
	double rate = 0;

	static const int percentage = 100;
};

class TaxFree
{
public:
	TaxFree() = default;

	TaxFree(string name, double money)
		: name(name), money(money) {}

	void SetName(string value)
	{
		name = value;
	}
	void SetMoney(double value)
	{
		money = value;
	}

	string GetName() const
	{
		return name;
	}
	double GetMoney() const
	{
		return money;
	}

private:
	string name = NULL;
	double money = 0;
};

class Tax
{
public:
	Tax() = default;

	Tax(double incomeTax)
		: incomeTax(incomeTax)
	{
		localIncomeTax = incomeTax / TEN;
	}

	void SetIncomeTax(double value)
	{
		incomeTax = value;
		localIncomeTax = value / TEN;
	}

	double GetIncomeTax() const
	{
		return incomeTax;
	}
	double GetLocalIncomeTax() const
	{
		return localIncomeTax;
	}

private:
	double incomeTax = 0;
	double localIncomeTax = 0;
};

struct TaxBill
{
public:
	int id = -1;

	Tax tax;

	vector<TaxFree> taxFrees;

	Insurance nationalPension;
	Insurance healthInsurance;
	Insurance longTermNursingInsurance;
	Insurance employmentInsurance;
};

class NationalTaxService
{
public:
	NationalTaxService() = default;
	NationalTaxService(vector<TaxBill> taxBills)
		: taxBills(taxBills) {}

	void AddTaxBill(TaxBill taxBill)
	{
		if (OverlapCheck(taxBill)) return;
		taxBills.push_back(taxBill);
	}

	void RemoveTaxBill(int id)
	{
		int count = 0;

		for (; count < taxBills.size(); count++)
		{
			if (taxBills[count].id == id) break;
		}

		taxBills.erase(taxBills.begin() + count);
	}

private:
	vector<TaxBill> taxBills;

	bool OverlapCheck(TaxBill value)
	{
		int check = 0;

		for (int count = 0; count < taxBills.size(); count++)
		{
			if (taxBills[count].id == value.id)
			{
				check++;
			}
		}

		return check > 0;
	}
};

struct ManagementHistory
{
public:
	int year = -1;

	double salary = 0;

	double totalTaxFree = 0;

	double nationalPension = 0;
	double healthInsurance = 0;
	double longTermNursingInsurance = 0;
	double employmentInsurance = 0;

	double incomeTax = 0;
	double localIncomeTax = 0;

	double moneyOfDepositMature = 0;
	double moneyOfSavingsMature = 0;

	double totalAsset = 0;
};

class MoneyManager
{
public:
	MoneyManager() = default;

	MoneyManager(int managementPeriod)
		: managementPeriod(managementPeriod) {}

	void PrintManagementHistory()
	{
		if (!IsSame()) return;

		vector<ManagementHistory> managementHistories = Calcurate();

		for (int count = 0; count < managementHistories.size(); count++)
		{
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << "- 공재액합계 -" << endl;
			cout << fixed << "국민연금 = " << managementHistories[count].nationalPension << "원" << endl;
			cout << fixed << "건강보험 = " << managementHistories[count].healthInsurance << "원" << endl;
			cout << fixed << "장기요양 = " << managementHistories[count].longTermNursingInsurance << "원" << endl;
			cout << fixed << "고용보험 = " << managementHistories[count].employmentInsurance << "원" << endl;
			cout << fixed << "소득세 = " << managementHistories[count].incomeTax << "원" << endl;
			cout << fixed << "지방소득세 = " << managementHistories[count].localIncomeTax << "원" << endl;
			cout << fixed << "월 실수령액 = " << managementHistories[count].salary << "원" << endl;
			cout << fixed << "\n예금만기수령액 : " << managementHistories[count].moneyOfDepositMature << "원" << endl;
			cout << fixed << "적금만기수령액 : " << managementHistories[count].moneyOfSavingsMature << "원" << endl;
			cout << fixed << managementHistories[count].year << "년 총 자산은 " << managementHistories[count].totalAsset << "원" << endl;
		}
	}

	vector<ManagementHistory> Calcurate()
	{
		if (!IsSame()) throw exception();

		time_t timer;
		struct tm t;

		timer = time(NULL);
		localtime_s(&t, &timer);

		int year = localtime_s(&t,&timer) + COMPUTERSTARTYEAR;

		double money2Save = 0;

		vector<ManagementHistory> managementHistories;

		for (int count1 = 0; count1 < managementPeriod; count1++)
		{
			ManagementHistory managementHistory;

			managementHistory.year = year++;

			managementHistory.salary = account.GetSalary();

			managementHistory.incomeTax = taxBill.tax.GetIncomeTax();
			managementHistory.localIncomeTax = taxBill.tax.GetLocalIncomeTax();

			for (int count2 = 0; count2 < taxBill.taxFrees.size(); count2++)
			{
				managementHistory.totalTaxFree += taxBill.taxFrees[count2].GetMoney();
			}
			
			managementHistory.salary -= managementHistory.totalTaxFree;

			managementHistory.nationalPension = taxBill.nationalPension.Calcurate(managementHistory.salary);
			managementHistory.healthInsurance = taxBill.healthInsurance.Calcurate(managementHistory.salary);
			managementHistory.longTermNursingInsurance = taxBill.longTermNursingInsurance.Calcurate(managementHistory.healthInsurance);
			managementHistory.employmentInsurance = taxBill.employmentInsurance.Calcurate(managementHistory.salary);

			managementHistory.salary -= managementHistory.nationalPension + managementHistory.healthInsurance + managementHistory.longTermNursingInsurance + managementHistory.employmentInsurance;

			managementHistory.salary -= managementHistory.incomeTax + managementHistory.localIncomeTax;

			managementHistory.salary += managementHistory.totalTaxFree;
			
			money2Save = managementHistory.salary - account.GetAmountConsumed();

			Savings savings = account.GetSavings();
			savings.SetMoney(money2Save);
			account.SetSavings(savings);

			managementHistory.moneyOfSavingsMature = account.GetSavings().Calcurate();
			managementHistory.moneyOfDepositMature = account.GetDeposit().Calcurate();

			managementHistory.totalAsset = managementHistory.moneyOfDepositMature + managementHistory.moneyOfSavingsMature;

			managementHistories.push_back(managementHistory);

			account.AYearLater();

			Deposit deposit = account.GetDeposit();
			deposit.SetMoney(deposit.GetMoney() + managementHistory.moneyOfSavingsMature);
			
			account.SetDeposit(deposit);
		}

		return managementHistories;
	}

	void SetManagementPeriod(int value)
	{
		managementPeriod = value;
	}
	void SetAccount(Account value)
	{
		account = value;
	}
	void SetTaxBill(TaxBill value)
	{
		taxBill = value;
	}

	int GetManagementPeriod() const
	{
		return managementPeriod;
	}
	Account GetAccount() const
	{
		return account;
	}
	TaxBill GetTaxBill() const
	{
		return taxBill;
	}

private:
	int managementPeriod = 0;

	Account account;
	TaxBill taxBill;

	bool IsSame() const
	{
		return account.GetID() == taxBill.id;
	}
};

using namespace Tools;
using namespace IncomeTaxManager;

int main()
{
	int id = 1;
	string name = "익명";

	Bank bank;
	NationalTaxService nationalTaxService;
	MoneyManager moneyManager(10);

	Account myAccount;
	TaxBill taxBill;

	myAccount.SetID(id);
	myAccount.SetName(name);
	myAccount.SetAnnualSalary(Input<double>("연봉을 입력하세요 : "));
	
	myAccount.SetRateOfSalaryIncrease(Input<double>("연봉인상율(%) : "));
	
	TaxFree taxFree("비과세", Input<double>("비과세액을 입력하세요 : "));
	taxBill.taxFrees.push_back(taxFree);

	cout << "1개월 총 소비액은 1300000원으로 고정" << endl;
	myAccount.SetAmountConsumed(1300000);

	Savings savings;
	savings.SetInterest(Input<double>("적금이자율(%) : "));
	savings.SetID(id);
	savings.SetYear(1);
	Deposit deposit;
	deposit.SetInterest(Input<double>("예금이자율(%) : "));
	deposit.SetID(id);
	deposit.SetYear(1);

	myAccount.SetDeposit(deposit);
	myAccount.SetSavings(savings);


	taxBill.id = id;
	taxBill.nationalPension.SetName("국민연금");
	taxBill.nationalPension.SetRate(4.5);
	taxBill.healthInsurance.SetName("건강보험");
	taxBill.healthInsurance.SetRate(3.495);
	taxBill.longTermNursingInsurance.SetName("장기요양보험");
	taxBill.longTermNursingInsurance.SetRate(12.27);
	taxBill.employmentInsurance.SetName("고용보험");
	taxBill.employmentInsurance.SetRate(0.9);
	taxBill.tax.SetIncomeTax(IncomeTax().Calcurate(myAccount.GetAnnualSalary()));

	nationalTaxService.AddTaxBill(taxBill);

	moneyManager.SetAccount(myAccount);
	moneyManager.SetTaxBill(taxBill);

	moneyManager.PrintManagementHistory();

	return 0;
}