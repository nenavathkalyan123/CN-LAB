// Include headers
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
// length of the generator polynomial
#define N strlen(gen_poly)
// data to be transmitted and received
char data[28];
// CRC value
char check_value[28];
// generator polynomial
char gen_poly[10];
// variables
int data_length,i,j;
// function that performs XOR operation
void XOR(){
// if both bits are the same, the output is 0
// if the bits are different the output is 1
for(j = 1;j &lt; N; j++)
check_value[j] = (( check_value[j] == gen_poly[j])?&#39;0&#39;:&#39;1&#39;);
}
// Function to check for errors on the receiver side
void receiver(){
// get the received data
printf(&quot;Enter the received data: &quot;);
scanf(&quot;%s&quot;, data);
printf(&quot;\n-----------------------------\n&quot;);
printf(&quot;Data received: %s&quot;, data);
// Cyclic Redundancy Check
crc();
// Check if the remainder is zero to find the error
for(i=0;(i&lt;N-1) &amp;&amp; (check_value[i]!=&#39;1&#39;);i++);
if(i&lt;N-1)
printf(&quot;\nError detected\n\n&quot;);
else
printf(&quot;\nNo error detected\n\n&quot;);
}
void crc(){
// initializing check_value
for(i=0;i&lt;N;i++)
check_value[i]=data[i];
do{
// check if the first bit is 1 and calls XOR function
if(check_value[0]==&#39;1&#39;)
XOR();
// Move the bits by 1 position for the next computation
for(j=0;j&lt;N-1;j++)
check_value[j]=check_value[j+1];
// appending a bit from data
check_value[j]=data[i++];
}while(i&lt;=data_length+N-1);

// loop until the data ends
}
int main()
{
// get the data to be transmitted
printf(&quot;\nEnter data to be transmitted: &quot;);
scanf(&quot;%s&quot;,data);
printf(&quot;\n Enter the Generating polynomial: &quot;);
// get the generator polynomial
scanf(&quot;%s&quot;,gen_poly);
// find the length of data
data_length=strlen(data);
// appending n-1 zeros to the data
for(i=data_length;i&lt;data_length+N-1;i++)
data[i]=&#39;0&#39;;
printf(&quot;\n----------------------------------------&quot;);
// print the data with padded zeros
printf(&quot;\n Data padded with n-1 zeros : %s&quot;,data);
printf(&quot;\n----------------------------------------&quot;);
// Cyclic Redundancy Check
crc();
// print the computed check value
printf(&quot;\nCRC or Check value is : %s&quot;,check_value);
// Append data with check_value(CRC)
for(i=data_length;i&lt;data_length+N-1;i++)
data[i]=check_value[i-data_length];
printf(&quot;\n----------------------------------------&quot;);
// printing the final data to be sent
printf(&quot;\n Final data to be sent : %s&quot;,data);
printf(&quot;\n----------------------------------------\n&quot;);
// Calling the receiver function to check errors
receiver();
return 0;
}
