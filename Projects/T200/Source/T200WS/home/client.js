class WebClient {
    constructor() {

    }

    open() {
        let ws = new WebSocket("ws://localhost:8888/server");
        
        ws.onopen = function(event) {
            alert(1);
            ws.send("hello");
        };

        ws.onmessage = function(event) {
            alert(2);
        };

        ws.onclose = function(event) {
            alert(3);
        }

    }
}