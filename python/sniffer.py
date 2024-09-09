from scapy.all import sniff

# define a callback function to handle each captured packet
def packet_callback(packet):
    if packet.haslayer("IP"):
        ip_layer = packet.getlayer("IP")
        print(f"Source IP: {ip_layer.src} -> Destination IP: {ip_layer.dst}")
    
        if packet.haslayer("TCP"):
            tcp_layer = packet.getlayer("TCP")
            print(f"TCP Packet - Source port: {tcp_layer.sport}, Destination Port: {tcp_layer.dport}")

        elif packet.haslayer("UDP"):
            udp_layer = packet.getlayer("UDP")
            print(f"UDP Packet - Source port: {udp_layer.sport}, Destination Port: {udp_layer.dport}")

# sniff packets on all available interfaces
sniff(prn=packet_callback, count=10)