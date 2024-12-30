var rear = "environment";
var front = "user";
var currentCamera = localStorage.getItem("currentCamera");
if(!currentCamera) currentCamera = front;
var mstream = null;
var track = null;
var lightOn = false;

function switchCamera() {
  if(!mstream) return;
  if(currentCamera==rear) currentCamera=front;
  else currentCamera = rear;
  localStorage.setItem("currentCamera",currentCamera);
  disconnectCamera();
  connectCamera();
}

function switchLight() {
  if(!mstream) return;
  lightOn = !lightOn;
  if(lightOn) {
    track.applyConstraints({
      advanced: [{torch:true}]
    });
  }
  else {
    // {torch:false} doesn't work
    disconnectCamera();
    connectCamera();
  }
}

function connectCamera() {
  connectSpecificCamera(currentCamera);
}

function disconnectCamera() {
  lightOn = false;  
  if(mstream) {
    track.applyConstraints({
      advanced: [{torch: false}]
    });
    track.stop();
    mstream = null;
  }
}

function connectSpecificCamera(which) {
  navigator.mediaDevices.getUserMedia({
    video: {
      facingMode:which,
      width: 1280,
      height: 720,
    },
  }).then(function(stream) {
    mstream = stream;
    track = mstream.getVideoTracks()[0];
    var video = document.getElementById('video');
    video.srcObject = stream;
    video.play();
  })
  .catch(function(err){
      android.toast.show(err);
  });
}

function startViewActivity(path) {
  var pn = android.activity.getPackageName();
  var intent = {
    component:{
        package: pn,
        className: pn+".ViewPhoto"
    },
    extras:{
        path: path
    }
  } 
  android.activity.startActivity(intent);
}

function savePic(data) {
  var dir = android.files.getFilesDir();
  var file = new android.File(dir,"pic.jpg");
  file.writeBase64(data);
  startViewActivity(file.toString());
}

function takePic() {
  var canvas = document.getElementById('canvas');
  var context = canvas.getContext('2d');
  var video = document.getElementById('video');
  var w = video.videoWidth;
  var h = video.videoHeight;
  canvas.width = w;
  canvas.height = h;
  context.drawImage(video, 0, 0,w ,h);
  var url = canvas.toDataURL("image/jpeg");
  var data = url.substring(url.indexOf(",")+1);
  savePic(data);
}

function onLoad() {
  if(!navigator||!navigator.mediaDevices||!navigator.mediaDevices.getUserMedia) {
    android.toast.show("This device is not supported.");
  }
  else connectCamera();
}


