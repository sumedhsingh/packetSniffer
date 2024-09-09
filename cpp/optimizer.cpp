#include <pcap.h>       // include the pcap library for packet capture 
#include <iostream>     // for standard i/o
using namespace std;

// Callback function to handle individual packets
void packet_handler(u_charc *user_data, const struct pcap_pkthdr *pkthdr, const u_char *packet){
    cout<<"Recieved packet with length: "<<pkthdr->len <<endl;
}

int main(){
    char errbuf[PCAP_ERRBUF_SIZE];      // buffer to store error messages
    pcap_t *handle = pcap_open_live("en0",BUFSIZ,1,1000,errbuf);  // opens the network interface

    if(handle == nullptr){
        std::cerr << "Error opening device: "<<errbuf<<endl;
        return 1;  // exit program if NIC is not opened
    }

    pcap_loop(handle,10,packet_handler,nullptr);    // capture 10 packets and call packet handler for each
    pcap_close(handle);     //close network interface
    
    return 0;

}

