// --- Some Codes are not included --- //
// --- Dynamic Web Interface matching the TFT Layout --- //
static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>Trash Bin Monitor Dashboard</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; background-color: #000000; color: #ffffff; text-align: center; margin: 0; padding: 20px; }
    .dashboard { display: flex; justify-content: center; align-items: center; max-width: 650px; margin: 30px auto; background: #050505; padding: 30px; border-radius: 16px; border: 2px solid #333; gap: 40px; }
    .left-panel { flex: 1; display: flex; justify-content: center; }
    .right-panel { flex: 1; text-align: left; display: flex; flex-direction: column; justify-content: center; }
    .bin-container { width: 120px; height: 260px; border: 4px solid #c0c0c0; border-radius: 8px; position: relative; background: #000; overflow: hidden; box-shadow: 0 0 15px rgba(0,0,128,0.3); }
    .bin-fill { width: 100%; position: absolute; bottom: 0; left: 0; transition: height 0.3s ease, background-color 0.5s ease; }
    h2 { font-size: 1.4rem; color: #aaaaaa; margin: 0 0 10px 0; letter-spacing: 1px; }
    .percentage-container { display: flex; align-items: baseline; margin-bottom: 10px; }
    .value { font-size: 5.5rem; font-weight: bold; line-height: 1; transition: color 0.5s ease; }
    .unit { font-size: 2.5rem; font-weight: bold; margin-left: 5px; }
    .label { font-size: 0.9rem; color: #888888; margin: 0; }
    .status-text { font-size: 2rem; font-weight: bold; margin: 5px 0; transition: color 0.5s ease; }
    .obstacle-text { font-size: 1.2rem; font-weight: bold; margin: 12px 0 4px 0; }
    .battery-text { font-size: 1.1rem; font-weight: bold; margin: 10px 0; }
    .distance-text { color: #ffff00; font-size: 1rem; }
    .alarm-banner { color: #ff0000; font-weight: bold; font-size: 1rem; margin-top: 15px; animation: blink 1s infinite; }
    @keyframes blink { 0%, 100% { opacity: 1; } 50% { opacity: 0; } }
    @media(max-width: 480px) { .dashboard { flex-direction: column; gap: 20px; padding: 15px; } .right-panel { text-align: center; align-items: center; } }
  </style>
</head>
<body>
  <h1 style="color: #ffffff; font-size: 1.8rem; margin-top: 10px;">BOAT MONITOR TELEMETRY</h1>
  <div class="dashboard">
    <div class="left-panel">
      <div class="bin-container">
        <div id="binFill" class="bin-fill"></div>
      </div>
    </div>
    <div class="right-panel">
      <h2>TRASH LEVEL</h2>
      <div class="percentage-container">
        <span id="binValue" class="value">0</span>
        <span id="binUnit" class="unit">%</span>
      </div>
      <div id="batteryStatus" class="battery-text">BATTERY: 100%</div>
      <p class="label">SYSTEM STATUS:</p>
      <div id="binStatus" class="status-text">NORMAL</div>
      <div id="obstacleStatus" class="obstacle-text">OBSTACLE: CLEAR</div>
      <div id="distanceStatus" class="distance-text">L:-cm R:-cm</div>
      <div id="alarmBox" class="alarm-banner" style="display:none;">!! BUZZER ACTIVE !!</div>
    </div>
  </div>
  <script>
    function updateTelemetry() {
      fetch('/bin_data').then(response => response.json()).then(data => {
        document.getElementById("binValue").textContent = data.fill_percentage;
        document.getElementById("binStatus").textContent = data.status;
        document.getElementById("obstacleStatus").textContent = "OBSTACLE: " + data.obstacle_status;
        document.getElementById("distanceStatus").textContent = "L:" + data.left_cm + "cm R:" + data.right_cm + "cm";
        
        let batElem = document.getElementById("batteryStatus");
        batElem.textContent = "BATTERY: " + data.battery_pct + "% (" + data.battery_volts + "V)";
        batElem.style.color = data.battery_alarm === 1 ? "#ff0000" : "#00ff00";

        let fillDiv = document.getElementById("binFill");
        fillDiv.style.height = data.fill_percentage + "%";

        let accentColor = "#00ff00";
        if(data.buzzer_alarm === 1) accentColor = "#ff0000";
        else if(data.fill_percentage >= 60) accentColor = "#ffa500";

        fillDiv.style.backgroundColor = accentColor;
        document.getElementById("binValue").style.color = accentColor;
        document.getElementById("binUnit").style.color = accentColor;
        document.getElementById("binStatus").style.color = accentColor;
        document.getElementById("obstacleStatus").style.color = data.obstacle_alarm === 1 ? "#ff0000" : "#00ff00";

        let alarmBox = document.getElementById("alarmBox");
        if(data.buzzer_alarm === 1) {
          alarmBox.style.display = "block";
          if (data.battery_alarm === 1) {
             alarmBox.textContent = "!! LOW BATTERY ALARM !!";
          } else {
             alarmBox.textContent = "!! BUZZER ACTIVE !!";
          }
        } else {
          alarmBox.style.display = "none";
        }
      }).catch(err => console.error("Data fetch error:", err));
    }
    setInterval(updateTelemetry, 500);
    window.onload = updateTelemetry;
  </script>
</body>
</html>
)rawliteral";