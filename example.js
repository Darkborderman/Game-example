//Setup a empty Game object
//store runtime items
//Like Game.engine or Game.map
let Game={};

//new Phaser.Game(Screen widthScreen height,CANVAS,div id,execute function order)
Game.engine= new Phaser.Game(1500,1000, Phaser.CANVAS, 'example', { preload: preload, create: create,update: update, render: render });

//Load assets that game needs
function preload() {
    Game.engine.load.image('logo', 'phaser.png');
}

//Create Game environment, like setup players, create maps...
function create() {
    //let phaser run even not focused
    Game.engine.stage.disableVisibilityChange = true;
    Game.logo=Game.engine.add.sprite(Game.engine.world.centerX, Game.engine.world.centerY, 'logo');
    Game.engine.physics.enable(Game.logo);
    Game.logo.anchor.setTo(0.5, 0.5);
}

//Game will loop this function to perform move,animations,...
function update(){
        Game.logo.body.velocity.x-=1;
        Game.logo.body.velocity.y-=1;
        Game.logo.body.collideWorldBounds=true;
        Game.logo.body.bounce.x=1;
        Game.logo.body.bounce.y=1;
}

//Usually store debug
function render(){

}