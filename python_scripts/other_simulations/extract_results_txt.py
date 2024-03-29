import sys
import os
from omnetpp.scave.results import *

#First argument - Input: Name of the data file (without the extension)
#Second argument - Output: Name of the results file (with extension(.txt))

if len(sys.argv) == 3:
    
    #Set of simulation result files to use as input
    set_inputs([sys.argv[1] + ".sca", sys.argv[1] + ".vec"])
    
    #Getting the number of channels used in the simulation
    numChannels=int(get_parameters("module=~TraficGeneratorNetwork.node[0] AND name=~numChannels")["value"].pop(0))
    
    if(os.path.exists(sys.argv[2])):
        os.remove(sys.argv[2])
        
    file=open(sys.argv[2], 'a')
    
    #Received packets per channel
    columnsReceivedPacketCount=''
    vectorReceivedPacketCount=np.zeros(numChannels)
    for i in range(numChannels):
        columnsReceivedPacketCount+='receivedPacketCount' + str(i) + ','
        receivedPacketCount=get_scalars("name=~receivedPacketCount" + str(i) + ":last")["value"].to_numpy()
        vectorReceivedPacketCount[i]=receivedPacketCount.mean()
    columnsReceivedPacketCount=columnsReceivedPacketCount[:-1]
    file.write(columnsReceivedPacketCount + "\n")
    np.savetxt(file, vectorReceivedPacketCount.reshape((1,numChannels)), fmt='%.0f', delimiter=',')
    print('ReceivedPacketCount processed')
    
    #CBT
    columnsCBT=''
    vectorCBT=np.zeros(numChannels)
    for i in range(numChannels):
        columnsCBT+='cbt' + str(i) + ','
        aux=get_vectors("name=~cbt" + str(i) + ":vector")["vecvalue"].to_numpy()
        cbt=np.concatenate(aux)
        vectorCBT[i]=cbt.mean()
    columnsCBT=columnsCBT[:-1]
    file.write(columnsCBT + "\n")
    np.savetxt(file, vectorCBT.reshape((1,numChannels)), fmt='%.4f', delimiter=',')
    print('CBT processed')
    
    #IRT
    columnsIRT=''
    vectorIRT=np.zeros(numChannels)
    for i in range(numChannels):
        columnsIRT+='irt' + str(i) + ','
        aux=get_vectors("name=~irt" + str(i) + ":vector")["vecvalue"].to_numpy()
        irt=np.concatenate(aux)
        vectorIRT[i]=np.percentile(irt, 99)
    columnsIRT=columnsIRT[:-1]
    file.write(columnsIRT + "\n")
    np.savetxt(file, vectorIRT.reshape((1,numChannels)), fmt='%.5f', delimiter=',')
    print('IRT processed')
    
    #PDR
    for i in range(numChannels):
        columnsPDR=''
        vectorPDR=np.zeros(20)
        for j in range(20):
            columnsPDR+="PDR" + str(i) + "_" + str(j*100) + "-" + str((j+1)*100) + ","
            aux=get_vectors("name=~pdr" + str(i) + "_" + str(j*100) + "-" + str((j+1)*100) + ":vector")["vecvalue"].to_numpy()
            if aux.size != 0:
                pdr=np.concatenate(aux)
                vectorPDR[j]=pdr.mean()
            else:
                vectorPDR[j]=0
        columnsPDR=columnsPDR[:-1]
        file.write(columnsPDR + "\n")
        np.savetxt(file, vectorPDR.reshape((1,20)), fmt='%.4f', delimiter=',')
        print('PDR channel ' + str(i) + ' processed')
    
    file.close()
    
else:
    print("Error - The number of arguments is invalid")
    