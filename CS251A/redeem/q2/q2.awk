#!/usr/bin/gawk
BEGIN{
no_users=0
i=0
xox=1
}
{
    if(i==0){
        for(j=1;j<NF+1;j++){
            fields[$j]=j
        }
        i=1
        user=fields["USER"]
    }else{
        #unique PID
        if(!data[$user,fields["PID"],$fields["PID"]]){
            data[$user,fields["PID"],$fields["PID"]]=1
            data[$user,fields["PID"]]=data[$user,fields["PID"]]+1
        }
        #memory for each USER
        data[$user,fields["SZ"]]=data[$user,fields["SZ"]]+$fields["SZ"]
        #Time calculation
        split($fields["TIME"],a,":")
        time=a[3]+a[2]*60+a[1]*3600
        data[$user,fields["TIME"]]=data[$user,fields["TIME"]]+time
        #thread id calculation
        data[$user,fields["LWP"]]=data[$user,fields["LWP"]]+1
        #unique user
        if (!data[$user]) {
            data[$user]=1
            userd[no_users]=$user
            no_users=no_users+1
        }
    }
}
END{
    print "That many users!!!!\t" no_users
    print "-------------------------------------------------------------------------------------------------------------------------------------------"
    printf "| %-25s | %-25s | %-25s | %-25s | %-25s|\n", "USER", "PID", "SZ", "LWP", "TIME"
    print "--------------------------------------------------------------------------------------------------------------------------------------------"
    for(k=0;k<no_users;k++){
        printf "| %-25s | %-25s | %-25s | %-25s | %-25s|\n", userd[k], data[userd[k],fields["PID"]], data[userd[k],fields["SZ"]], data[userd[k],fields["LWP"]], data[userd[k],fields["TIME"]]
    }
    print "--------------------------------------------------------------------------------------------------------------------------------------------"
}
