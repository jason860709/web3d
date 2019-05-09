var shelljs = require('shelljs');
var express = require('express');
var app = express();

app.get('/', function(req, res){
  res.sendFile(__dirname + '/hw4.html');
});

app.get ('/api', function (req, res) {

	console.log ('url:' + req.url);

	var RmaxX = req.query.RmaxX;
	var RmaxY = req.query.RmaxY;
	var RminX = req.query.RminX;
	var RminY = req.query.RminY;
	var Cx = req.query.Cx;
	var Cy = req.query.Cy;
	var radius = req.query.radius;	// ("argv");
	//console.log (argv);
		
	shelljs.exec('CircleRect.exe ' + RmaxX + ' ' + RmaxY + ' ' + RminX + ' ' + RminY + ' ' + Cx + ' ' + Cy + ' ' + radius, function(status, output) {
	  //console.log('Exit status:', status);
		  
          var output = {
          	status: status,
          	output: output
          };

          /*
            The response header for supporting CORS:
            "Access-Control-Allow-Origin": "*",
            "Access-Control-Allow-Headers": "Content-Type"
          */

		  res.writeHead(200, {
		  	"Content-Type": "application/json",
            "Access-Control-Allow-Origin": "*",
            "Access-Control-Allow-Headers": "Content-Type"
		  });
	
		  res.write(JSON.stringify(output));
		  res.end();

	});
});


// or simply
// app.listen (1337); 
// will do

var server = app.listen (1337, function() {
	var host = server.address().address;
	var port = server.address().port;
	console.log ('server started on http://' + host + ':' + port);
});
