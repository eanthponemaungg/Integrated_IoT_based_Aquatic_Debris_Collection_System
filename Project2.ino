// --- Some codes are not included --- //
// =====================================================
// WEB PAGE
// =====================================================
static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 Trash Boat</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      margin: 0;
      padding-top: 15px;
      background: #e0f2f1;
      color: #333;
    }
    .container {
      max-width: 500px;
      margin: auto;
      padding: 10px;
    }
    h2 {
      color: #004d40;
      margin-bottom: 5px;
    }
    img {
      max-width: 100%;
      height: auto;
      border-radius: 12px;
      box-shadow: 0 4px 8px rgba(0,0,0,.2);
    }
    .grid-container {
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: 10px;
      margin: 20px auto;
      max-width: 300px;
    }
    button {
      border: none;
      color: white;
      padding: 15px;
      font-size: 16px;
      font-weight: bold;
      cursor: pointer;
      border-radius: 8px;
      box-shadow: 0 4px #666;
    }
    button:active {
      box-shadow: 0 1px #666;
      transform: translateY(3px);
    }
    .btn-nav { background: #00796b; }
    .btn-stop { background: #d32f2f; }
    .btn-action {
      background: #f57c00;
      width: 130px;
      margin: 5px;
    }
    .btn-auto-off {
      background: #757575;
      width: 200px;
      margin: 15px auto;
      padding: 18px;
      font-size: 18px;
      display: block;
    }
    .btn-auto-on {
      background: #2e7d32;
      width: 200px;
      margin: 15px auto;
      padding: 18px;
      font-size: 18px;
      display: block;
      animation: pulse 1.5s infinite;
    }
    .status-box {
      font-size: 18px;
      font-weight: bold;
      background: white;
      padding: 10px;
      border-radius: 8px;
      margin: 15px auto;
      max-width: 300px;
    }
    .empty-cell { visibility: hidden; }

    @keyframes pulse {
      0% { opacity: .8; }
      50% { opacity: 1; }
      100% { opacity: .8; }
    }
  </style>
</head>

<body>
  <div class="container">
    <h2>Trash Collector Remote</h2>

    <div class="status-box">
      Status: <span id="status">Connecting...</span>
    </div>

    <img src="" id="stream_view"><br><br>

    <button
      id="autoBtn"
      class="btn-auto-off"
      onclick="sendCmd('toggle_auto')">
      AUTO RUN: OFF
    </button>

    <div style="font-weight:bold;margin-top:10px;">
      MANUAL CONTROL
    </div>

    <div class="grid-container">
      <div class="empty-cell"></div>
      <button class="btn-nav" onclick="sendCmd('forward')">FW</button>
      <div class="empty-cell"></div>

      <button class="btn-nav" onclick="sendCmd('left')">LEFT</button>
      <button class="btn-stop" onclick="sendCmd('stop')">STOP</button>
      <button class="btn-nav" onclick="sendCmd('right')">RIGHT</button>

      <div class="empty-cell"></div>
      <button class="btn-nav" onclick="sendCmd('reverse')">REV</button>
      <div class="empty-cell"></div>
    </div>

    <div style="font-weight:bold;margin-top:15px;">
      CONVEYOR BELT
    </div>

    <button class="btn-action" onclick="sendCmd('conv_fw')">
      Collect (FW)
    </button>

    <button class="btn-action" onclick="sendCmd('conv_rev')">
      Eject (REV)
    </button>
  </div>

  <script>
    function sendCmd(action) {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/action?go=" + action, true);
      xhr.send();
      setTimeout(updateStatus, 150);
    }

    function updateStatus() {
      fetch("/state")
        .then(r => r.json())
        .then(data => {
          document.getElementById("status").textContent = data.status;

          let autoBtn = document.getElementById("autoBtn");

          if (data.auto) {
            autoBtn.textContent = "AUTO RUN: ACTIVE";
            autoBtn.className = "btn-auto-on";
          } else {
            autoBtn.textContent = "AUTO RUN: OFF";
            autoBtn.className = "btn-auto-off";
          }
        });
    }

    window.onload = () => {
      document.getElementById("stream_view").src =
        window.location.origin + ":81/stream";

      setInterval(updateStatus, 1000);
    }
  </script>
</body>
</html>
)rawliteral";