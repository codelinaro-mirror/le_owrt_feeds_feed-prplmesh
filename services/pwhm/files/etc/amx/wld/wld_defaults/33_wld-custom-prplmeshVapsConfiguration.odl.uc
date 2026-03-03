%populate {
    object WiFi {
        object AccessPoint {
{% for ( let Itf in BD.Interfaces ) : if ( BDfn.isInterfaceWirelessAp(Itf.Name) && BDfn.isInterfaceGuest(Itf.Name) ) : %}
{% if (Itf.OperatingFrequency != "") : %}
            object '{{Itf.Alias}}' {
                parameter MultiAPType = "FronthaulBSS";
            }
{% endif%}
{% endif; endfor; %}
        }
    }
}
