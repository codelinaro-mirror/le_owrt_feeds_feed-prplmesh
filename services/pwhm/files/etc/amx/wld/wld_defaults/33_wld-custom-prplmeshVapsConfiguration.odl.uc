%populate {
    object WiFi {
        object AccessPoint {
{% let apindex = 0 %}
{% for ( let Itf in BD.Interfaces ) : if ( BDfn.isInterfaceWirelessAp(Itf.Name) ) : %}
{% if (Itf.OperatingFrequency != "") : %}
{% apindex = BDfn.getInterfaceIndex(Itf.Name, "wireless")  %}
            object '{{Itf.Alias}}' {
                parameter MultiAPType = "FronthaulBSS";
{% if (BDfn.isInterfaceGuest(Itf.Name)) : %}
{% if (Itf.OperatingFrequency == "2.4GHz") : %}
                parameter CustomAlias = "vap24gguest";
{% elif (Itf.OperatingFrequency == "5GHz") : %}
                parameter CustomAlias = "vap5gguest";
{% elif (Itf.OperatingFrequency == "6GHz") : %}
                parameter CustomAlias = "vap6gguest";
{% endif %}
{% else %}
{% if (Itf.OperatingFrequency == "2.4GHz") : %}
                parameter CustomAlias = "vap24ghome";
{% elif (Itf.OperatingFrequency == "5GHz") : %}
                parameter CustomAlias = "vap5ghome";
{% elif (Itf.OperatingFrequency == "6GHz") : %}
                parameter CustomAlias = "vap6ghome";
{% endif %}
{% endif %}
            }
{% endif%}
{% endif; endfor; %}
        }
    }
}
