%populate {
    object WiFi {
        object AccessPoint {
{% let apindex = 0 %}
{% for ( let Itf in BD.Interfaces ) : if ( BDfn.isInterfaceWirelessAp(Itf.Name) ) : %}
            object '{{Itf.Alias}}' {
{% if (BDfn.isInterfaceLan(Itf.Name)) : %}
                parameter BridgeInterface = "{{BD.Bridges.Lan.Name}}";
{% elif (BDfn.isInterfaceGuest(Itf.Name)) : %}
                parameter BridgeInterface = "{{BD.Bridges.Guest.Name}}";
{% endif %}
            }
{% endif; endfor; %}
        }
    }
}
