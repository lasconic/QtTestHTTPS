import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    title: qsTr("Hello World")

    Image {
       id: image
       width:parent.width
       source: "https://d1jdgm35warl9f.cloudfront.net/images/logo.png"
       smooth: true
       fillMode: Image.PreserveAspectFit
       onStatusChanged: {
            console.log(image.status)
            if (image.status === Image.Ready)
                console.log("HTTPS with QML Image  : OK")
            else if (image.status === Image.Error)
                console.log("HTTPS with QML Image : KO")
       }
    }

    Item {
       id: test
       Component.onCompleted: {
           var req = new XMLHttpRequest();
           var url = "https://musescore.com"

           req.onreadystatechange = function() {
                       if (req.readyState === 4) {
                           //console.log( req.status + " - " + req.statusText );
                           if (req.responseText.indexOf("<!DOCTYPE html>") == 0)
                               console.log("HTTPS with XMLHttpRequest : OK")
                           else
                               console.log("HTTPS with XMLHttpRequest : KO")
                       }
           }

           req.open("GET",url ,true)
           req.send()
       }
    }
}
