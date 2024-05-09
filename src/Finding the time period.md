Core algorithm logic
============

Map: countvisitors
------------
This is an ordered map which keep track of entry and exit time of visitors according to the below logics : 

* 1- key => entry time , value => value+=1 { to keep count of all visitors coming at this entry time }
* 2- key => exit time , value => value=0 { to take care of leaving time inclusion logic }
* 3- key => exit time + 1 , value => value-=1 { to accomodate count of visitors already left }

we took ordered map so that data is sorted according to time as key

Function : findmaxvisitortimeperiod
------------

we loop over countvisitors map and keep on updating maxvisitor , maxstarttime and maxendtime.
(currentvisitor == maxvisitor && maxvisitor != 0) - here in this condition we make use of condition 2 while 
filling countvisitors map above and fill the appropriate maxenditme.