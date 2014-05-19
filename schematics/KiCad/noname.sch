EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "19 may 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM555N C2
U 1 1 537A2C27
P 7200 3200
F 0 "C2" H 7200 3300 70  0000 C CNN
F 1 "LM555N" H 7200 3100 70  0000 C CNN
F 2 "" H 7200 3200 60  0000 C CNN
F 3 "" H 7200 3200 60  0000 C CNN
F 4 "40KHz" H 7200 3200 60  0000 C CNN "Frec"
	1    7200 3200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 537A2C80
P 4100 2450
F 0 "#PWR?" H 4100 2540 20  0001 C CNN
F 1 "+5V" H 4100 2540 30  0000 C CNN
F 2 "" H 4100 2450 60  0000 C CNN
F 3 "" H 4100 2450 60  0000 C CNN
	1    4100 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2450 4100 3500
Wire Wire Line
	4100 3500 4350 3500
$Comp
L GND #PWR?
U 1 1 537A2CC5
P 4550 4500
F 0 "#PWR?" H 4550 4500 30  0001 C CNN
F 1 "GND" H 4550 4430 30  0001 C CNN
F 2 "" H 4550 4500 60  0000 C CNN
F 3 "" H 4550 4500 60  0000 C CNN
	1    4550 4500
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 537A2CE3
P 4200 3800
F 0 "C2" H 4200 3900 40  0000 L CNN
F 1 "10nF" H 4206 3715 40  0000 L CNN
F 2 "~" H 4238 3650 30  0000 C CNN
F 3 "~" H 4200 3800 60  0000 C CNN
	1    4200 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3250 4200 3250
Wire Wire Line
	4200 4000 5050 4000
$Comp
L DIODE D1
U 1 1 537A2D3A
P 6250 4000
F 0 "D1" H 6250 4100 40  0000 C CNN
F 1 "DIODE" H 6250 3900 40  0001 C CNN
F 2 "~" H 6250 4000 60  0000 C CNN
F 3 "~" H 6250 4000 60  0000 C CNN
	1    6250 4000
	0    -1   1    0   
$EndComp
$Comp
L R R1
U 1 1 537A2D49
P 5950 4000
F 0 "R1" V 6030 4000 40  0000 C CNN
F 1 "8K" V 5957 4001 40  0000 C CNN
F 2 "~" V 5880 4000 30  0000 C CNN
F 3 "~" H 5950 4000 30  0000 C CNN
	1    5950 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3750 6250 3750
Wire Wire Line
	6250 3750 6250 3800
Wire Wire Line
	5950 4250 6250 4250
Wire Wire Line
	6250 4250 6250 4200
Wire Wire Line
	5750 3200 6100 3200
Wire Wire Line
	6100 2550 6100 3750
Connection ~ 6100 3750
Wire Wire Line
	6100 4350 6100 4250
Wire Wire Line
	3900 4350 6100 4350
Wire Wire Line
	5750 4350 5750 3400
Connection ~ 6100 4250
Wire Wire Line
	5750 3000 6250 3000
Wire Wire Line
	6250 3000 6250 3500
Wire Wire Line
	6250 3500 6500 3500
$Comp
L CP1 C1
U 1 1 537A2E58
P 5250 4000
F 0 "C1" H 5300 4100 50  0000 L CNN
F 1 "4.7uF" H 5300 3900 50  0000 L CNN
F 2 "~" H 5250 4000 60  0000 C CNN
F 3 "~" H 5250 4000 60  0000 C CNN
	1    5250 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	5450 4000 5750 4000
Connection ~ 4550 4000
$Comp
L R R2
U 1 1 537A2EB3
P 5000 2550
F 0 "R2" V 5080 2550 40  0000 C CNN
F 1 "2K" V 5007 2551 40  0000 C CNN
F 2 "~" V 4930 2550 30  0000 C CNN
F 3 "~" H 5000 2550 30  0000 C CNN
	1    5000 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 2550 4100 2550
Connection ~ 4100 2550
Wire Wire Line
	5250 2550 6100 2550
Connection ~ 6100 3200
Wire Wire Line
	4350 3000 3900 3000
Wire Wire Line
	3900 3000 3900 4350
Connection ~ 5750 4350
$Comp
L LM555N C1
U 1 1 537A2A28
P 5050 3200
F 0 "C1" H 5050 3300 70  0000 C CNN
F 1 "LM555N" H 5050 3100 70  0000 C CNN
F 2 "" H 5050 3200 60  0000 C CNN
F 3 "" H 5050 3200 60  0000 C CNN
F 4 "30Hz" H 5050 3200 60  0000 C CNN "Frec"
	1    5050 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3250 4200 3600
$EndSCHEMATC
