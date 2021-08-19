EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RF_Module:ESP-12F U1
U 1 1 6063344F
P 6000 3700
F 0 "U1" H 6000 4678 50  0000 C CNN
F 1 "ESP-12F" H 6000 4587 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 6000 3700 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 5650 3800 50  0001 C CNN
	1    6000 3700
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U3
U 1 1 6063359F
P 3450 3200
F 0 "U3" H 3450 2833 50  0000 C CNN
F 1 "LM358" H 3450 2924 50  0000 C CNN
F 2 "" H 3450 3200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 3450 3200 50  0001 C CNN
	1    3450 3200
	-1   0    0    1   
$EndComp
$Comp
L Device:Buzzer BZ1
U 1 1 60633DBB
P 3100 2300
F 0 "BZ1" V 3152 2113 50  0000 R CNN
F 1 "Buzzer" V 3061 2113 50  0000 R CNN
F 2 "" V 3075 2400 50  0001 C CNN
F 3 "~" V 3075 2400 50  0001 C CNN
	1    3100 2300
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x07_Male .
U 1 1 6063408E
P 7250 1200
F 0 "." V 7223 1130 50  0000 R CNN
F 1 "DISPLAY" V 7223 1221 50  0000 C CNN
F 2 "" H 7250 1200 50  0001 C CNN
F 3 "~" H 7250 1200 50  0001 C CNN
	1    7250 1200
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x06_Male J3
U 1 1 606341F9
P 9000 3650
F 0 "J3" H 8972 3530 50  0000 R CNN
F 1 "SD_SHIELD" H 8972 3621 50  0000 R CNN
F 2 "" H 9000 3650 50  0001 C CNN
F 3 "~" H 9000 3650 50  0001 C CNN
	1    9000 3650
	-1   0    0    1   
$EndComp
$Comp
L Regulator_Linear:LM7805_TO220 U2
U 1 1 60634432
P 7200 4600
F 0 "U2" H 7200 4842 50  0000 C CNN
F 1 "LM7805" H 7200 4751 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7200 4825 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 7200 4550 50  0001 C CNN
	1    7200 4600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Jack-DC J4
U 1 1 606344FA
P 6050 5700
F 0 "J4" V 6152 5520 50  0000 R CNN
F 1 "Jack-DC" V 6061 5520 50  0000 R CNN
F 2 "" H 6100 5660 50  0001 C CNN
F 3 "~" H 6100 5660 50  0001 C CNN
	1    6050 5700
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 606345AF
P 6450 4600
F 0 "C1" V 6198 4600 50  0000 C CNN
F 1 "0.33uf" V 6289 4600 50  0000 C CNN
F 2 "" H 6488 4450 50  0001 C CNN
F 3 "~" H 6450 4600 50  0001 C CNN
	1    6450 4600
	0    1    1    0   
$EndComp
$Comp
L Device:C C2
U 1 1 60634611
P 7700 4750
F 0 "C2" H 7815 4796 50  0000 L CNN
F 1 "0.1uf" H 7815 4705 50  0000 L CNN
F 2 "" H 7738 4600 50  0001 C CNN
F 3 "~" H 7700 4750 50  0001 C CNN
	1    7700 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male .
U 1 1 60634A62
P 3550 4650
F 0 "." H 3656 4928 50  0000 C CNN
F 1 "AS608" H 3656 4837 50  0000 C CNN
F 2 "" H 3550 4650 50  0001 C CNN
F 3 "~" H 3550 4650 50  0001 C CNN
	1    3550 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 60634CDC
P 3200 3900
F 0 "R2" H 3270 3946 50  0000 L CNN
F 1 "100k" H 3270 3855 50  0000 L CNN
F 2 "" V 3130 3900 50  0001 C CNN
F 3 "~" H 3200 3900 50  0001 C CNN
	1    3200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 5400 6150 5150
Wire Wire Line
	6150 4400 6000 4400
Wire Wire Line
	5950 5400 5650 5400
Wire Wire Line
	4450 5400 4450 2900
Wire Wire Line
	4450 2900 6000 2900
Wire Wire Line
	7200 4900 6150 4900
Connection ~ 6150 4900
Wire Wire Line
	6150 4900 6150 4400
Wire Wire Line
	6900 4600 6600 4600
Wire Wire Line
	6300 4600 5650 4600
Wire Wire Line
	5650 4600 5650 5400
Connection ~ 5650 5400
Wire Wire Line
	5650 5400 4750 5400
Wire Wire Line
	7200 4900 7700 4900
Wire Wire Line
	8800 4900 8800 3850
Connection ~ 7200 4900
Wire Wire Line
	7500 4600 7700 4600
Wire Wire Line
	8600 4600 8600 4050
Wire Wire Line
	8600 3750 8800 3750
Connection ~ 7700 4600
Wire Wire Line
	7700 4600 8600 4600
Connection ~ 7700 4900
Wire Wire Line
	7700 4900 8350 4900
Wire Wire Line
	8800 3650 7950 3650
Wire Wire Line
	7950 3650 7950 2400
Wire Wire Line
	7950 2400 7250 2400
Wire Wire Line
	4600 2400 4600 3800
Wire Wire Line
	4600 3800 5400 3800
Wire Wire Line
	8800 3550 8150 3550
Wire Wire Line
	8150 3550 8150 2200
Wire Wire Line
	4850 2200 4850 4100
Wire Wire Line
	4850 4100 5400 4100
Wire Wire Line
	4850 2200 7050 2200
Wire Wire Line
	8800 3450 8300 3450
Wire Wire Line
	8300 3450 8300 2000
Wire Wire Line
	8300 2000 7350 2000
Wire Wire Line
	5050 2000 5050 4200
Wire Wire Line
	5050 4200 5400 4200
Wire Wire Line
	8800 3350 8500 3350
Wire Wire Line
	8500 3350 8500 1850
Wire Wire Line
	8500 1850 4750 1850
Wire Wire Line
	4750 1850 4750 3700
Wire Wire Line
	4750 3700 5400 3700
Wire Wire Line
	6950 1400 6950 3500
Wire Wire Line
	6950 3500 6600 3500
Wire Wire Line
	7550 1400 7800 1400
Wire Wire Line
	7800 1400 7800 4200
Wire Wire Line
	7800 4200 8350 4200
Wire Wire Line
	8350 4200 8350 4900
Connection ~ 8350 4900
Wire Wire Line
	8350 4900 8800 4900
Wire Wire Line
	7450 1400 7450 1500
Wire Wire Line
	7450 1500 7650 1500
Wire Wire Line
	7650 1500 7650 4050
Wire Wire Line
	7650 4050 8600 4050
Connection ~ 8600 4050
Wire Wire Line
	8600 4050 8600 3750
Wire Wire Line
	7350 1400 7350 2000
Connection ~ 7350 2000
Wire Wire Line
	7350 2000 5050 2000
Wire Wire Line
	6600 4100 7150 4100
Wire Wire Line
	7150 4100 7150 1400
Wire Wire Line
	7050 1400 7050 2200
Connection ~ 7050 2200
Wire Wire Line
	7050 2200 8150 2200
Wire Wire Line
	7250 1400 7250 2400
Connection ~ 7250 2400
Wire Wire Line
	7250 2400 4600 2400
Wire Wire Line
	3750 4550 4050 4550
Wire Wire Line
	4050 4550 4050 2900
Wire Wire Line
	4050 2900 4450 2900
Connection ~ 4450 2900
Wire Wire Line
	3750 4650 5150 4650
Wire Wire Line
	5150 4650 5150 5150
Wire Wire Line
	5150 5150 6150 5150
Connection ~ 6150 5150
Wire Wire Line
	6150 5150 6150 4900
Wire Wire Line
	3750 4750 5250 4750
Wire Wire Line
	5250 4750 5250 2700
Wire Wire Line
	5250 2700 7300 2700
Wire Wire Line
	7300 2700 7300 3900
Wire Wire Line
	7300 3900 6600 3900
Wire Wire Line
	3750 4850 4250 4850
Wire Wire Line
	4250 4850 4250 3200
Wire Wire Line
	4250 3200 5150 3200
Wire Wire Line
	5150 3200 5150 2550
Wire Wire Line
	5150 2550 6800 2550
Wire Wire Line
	6800 2550 6800 3700
Wire Wire Line
	6800 3700 6600 3700
Wire Wire Line
	3750 3300 3750 4000
Wire Wire Line
	3750 4000 5400 4000
Wire Wire Line
	3750 3100 3900 3100
Wire Wire Line
	3900 3100 3900 4400
Wire Wire Line
	3900 4400 6000 4400
Connection ~ 6000 4400
Wire Wire Line
	3000 2400 3000 3200
Wire Wire Line
	3000 3200 3150 3200
Wire Wire Line
	3200 2400 3900 2400
Wire Wire Line
	3900 2400 3900 3100
Connection ~ 3900 3100
Wire Wire Line
	5400 3500 3200 3500
Wire Wire Line
	3200 3500 3200 3750
Wire Wire Line
	3200 4050 3200 4250
Wire Wire Line
	3200 4250 4750 4250
Wire Wire Line
	4750 4250 4750 5400
Connection ~ 4750 5400
Wire Wire Line
	4750 5400 4450 5400
$EndSCHEMATC
