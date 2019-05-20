var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var port = process.env.PORT || 3000;
let name,count;
let namee = [];
app.get('/', function(req, res){
  res.sendFile(__dirname + '/h1.html');
});

app.get ('/change', function(req,res){
	name = req.query.name;
	count = 0;
	for(var i = 0;i<namee.length;i++){
		if(namee[i]==name){
			count++
		}
	}
	if(count==0){
		namee.push(name);
		console.log (name + ' is on ...')
		res.sendFile(__dirname + '/h1p.html')
	}
	else{

		res.sendFile(__dirname + '/h1.html');
	}
});

io.on('connection', function(socket){  // connection is same as connect
  socket.on('chat message', function(data){
	  data.id = socket.id;
    io.emit('chat message', data);
  });
});

http.listen(port, function(){
  console.log('listening on *:' + port);
});