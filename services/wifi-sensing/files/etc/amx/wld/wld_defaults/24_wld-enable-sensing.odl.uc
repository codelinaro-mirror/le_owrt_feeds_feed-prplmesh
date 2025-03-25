%populate {
    object WiFi {
        object Radio {
{% for ( let Radio in BD.Radios ) : %}
            object '{{Radio.Alias}}' {
                object Sensing {
                    parameter Enable = 1;
                }
                parameter SupportedSensingDataTypes = "AC9A9680";
                parameter SupportedSensingExchangeTypes = "qosnull";
            }
{% endfor; %}
        }
    }
}
