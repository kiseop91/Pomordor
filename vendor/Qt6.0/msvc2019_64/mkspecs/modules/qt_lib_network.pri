QT.network.VERSION = 6.0.0
QT.network.name = QtNetwork
QT.network.module = Qt6Network
QT.network.libs = $$QT_MODULE_LIB_BASE
QT.network.ldflags = 
QT.network.includes = $$QT_MODULE_INCLUDE_BASE $$QT_MODULE_INCLUDE_BASE/QtNetwork
QT.network.frameworks = 
QT.network.bins = $$QT_MODULE_BIN_BASE
QT.network.plugin_types = networkaccessbackends
QT.network.depends =  core
QT.network.uses = 
QT.network.module_config = v2
QT.network.DEFINES = QT_NETWORK_LIB
QT.network.enabled_features = ssl dtls ocsp opensslv11 http udpsocket networkproxy socks5 networkinterface networkdiskcache localserver dnslookup sspi topleveldomain openssl
QT.network.disabled_features = corewlan getifaddrs ipv6ifname securetransport schannel sctp brotli gssapi
QT_CONFIG += ssl dtls ocsp opensslv11 http udpsocket networkproxy socks5 networkinterface networkdiskcache localserver dnslookup sspi topleveldomain openssl
QT_MODULES += network

