Hi ✋

This programme simulate clearance of patients in a hospital.
If you want run this programm, you must edit variables below:

maxDaysForIcuAndHOSPITAL_WARD_BEDS = 6 // max days that take for any patients in ICU or HOSPITAL_WARD

NUMBER_OF_HOSPITAL_WARD_BEDS = 7;

NUMBER_OF_ICU_BEDS = 10;

NUMBER_SURGERY = 2;

NUMBER_OF_DAYS = 10; // you must edit this vars for number of deays you want simulate hospital process

the output is text file ( OUT.txt ) that show the process.
from this resault you can make decision on add more beds to ICU or HOSPITAL_WARD ???

notice:
this programme make random days for new patients in ICU and HOSPITAL_WARD, this random number is between 1 and maxDaysForIcuAndHOSPITAL_WARD_BEDS.

the process that consider for this programme is a new patient first reception in ICU for random days between 1 and maxDaysForIcuAndHOSPITAL_WARD_BEDS
after that goes to surgery room and after goes to hospital_ward and reception in it for random days between 1 and maxDaysForIcuAndHOSPITAL_WARD_BEDS
at the end he/she can go home😊.
