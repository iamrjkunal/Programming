#!/usr/bin/gawk
BEGIN{
}
{

packets[$3":"$5]++
if($NF !=0)
{
datapackets[$3":"$5]++
sequences[$3":"$5":"$9]=$9

}

bytes[$3":"$5] = bytes[$3":"$5] + $NF

if(!last_packet[$3":"$5])
{
first_packet[$3":"$5]=$1
last_packet[$3":"$5]=$1
retransmission[$3":"$5]=0
}

last_packet[$3":"$5] = $1



}
END{
  for(var in packets){
    if(flag[var] !=1){   
	split(var,ip,":")
        rev_var=ip[2]":"ip[1]":"
        
        split(first_packet[var],t1,":")
        split(last_packet[var],t2,":")
        total_time= 3600*(t2[1]-t1[1]) +60*(t2[2]-t1[2]) + (t2[3]-t1[3])
        
        split(first_packet[rev_var],T1,":")
        split(last_packet[rev_var],T2,":")
        rev_total_time= 3600*(T2[1]-T1[1]) +60*(T2[2]-T1[2]) + (T2[3]-T1[3])
        
        split(ip[1],ip_1,".")
        orginal_ip_1= ip_1[1]"."ip_1[2]"."ip_1[3]"."ip_1[4]"."ip_1[5]
        
        split(ip[2],ip_2,".")
        original_ip_2= ip_2[1]"."ip_2[2]"."ip_2[3]"."ip_2[4]"."ip_2[5]
        
        print "Connection (A="orginal_ip_1" B="original_ip_2")\n"
        printf "A-->B #packets=%d, #datapackets=%d, #bytes=%s, #retrans=%d xput=%d bytes/sec\n",packets[var],datapackets[var],bytes[var],0,int(bytes[var]/total_time)
        printf "B-->A #packets=%d, #datapackets=%d, #bytes=%s, #retrans=%d xput=%d bytes/sec\n",packets[rev_var],datapackets[rev_var],bytes[rev_var],0,int(bytes[rev_var]/rev_total_time)
	
	flag[rev_var]=1
        
     }

  }

}
