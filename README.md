# gr-notchFIlter

An OOT(out-of-tree) module for gnuradio, tyring  to implement notch filter

#Requirements


gnuradio 3.9+

# Installation

As recommanded by gnuradio installation guide, the OOT should better be installed from source.

First, download the package and unzip to a local folder.

Enter the folder consisting 'build' folder.

Open terminal here.

**Enter the 'build' folder:**
```shell
cd build
```
**run cmake and make:**
```shell
cmake ..

make

sudo make install
```
**link the module to the system:**
```shell
sudo ldconfig
```
# Blocks

**adaptiveNotch**

An adaptive notch filter with LMS method. Two parameters are needed: sampRate, targetFreq. 

This block first generate a cosin function (f1) and a sin function (f2), and combine them by: 

y=w1\*f1+w2\*f2

than compare y with input signal:

e=input-y

e also functions as output signal

than update w1 and w2:

w1=0.01e\*f1

w2=0.01e\*f2

**iirnotch**

An iir notch filter. transfer function is 

(s\*s+wc\*wc)\(s\*s+wc\*wc+wb\*s)

wc is the target frequency to be filtered

wb is the bandwidth to be filtered

