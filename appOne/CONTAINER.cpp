#include"input.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"ANIMS.h"
CONTAINER::~CONTAINER() {
	//１つのアニメーションの開放
	//delete Data.explosionChara.anim;
	delete Data.catChara.anim;
	delete Data.loading.anim;
	//複数のアニメーションの開放
	delete Data.pumpkinChara.anims;
	delete Data.enemyChara.anims;
	delete Data.playerChara.anims;
}
void CONTAINER::load() {
	CreateData();
	LoadGraphics();
}
void CONTAINER::CreateData() {
	//メッセージクラスのデータ
		//ストーリーに使用するウィンドウのデータ
	Data.message.sw = 3;
	Data.message.textSize = 30;
	Data.message.textPosOfst.x = 50;
	Data.message.textPosOfst.y = 50;
	Data.message.winH = 195;
	Data.message.windowPos.x = width / 2;
	Data.message.windowPos.y = height - Data.message.winH - Data.message.sw + 95;
	Data.message.winW = width - Data.message.sw * 2 - 200;
	Data.message.textPos.x = Data.message.windowPos.x + Data.message.textPosOfst.x - Data.message.winW / 2;
	Data.message.textPos.y = Data.message.windowPos.y + Data.message.textPosOfst.y - Data.message.winH / 2;
	Data.message.charaNameTextSize = 50;
	Data.message.textColor = COLOR(0, 0, 0);
	Data.message.winColor = COLOR(255, 255, 255);
	Data.message.edgeColor = COLOR(0, 0, 0);

	//注意書きに使用するウィンドウのデータ
	Data.message.attentionWinPos.x = Data.message.windowPos.x;
	Data.message.attentionWinPos.y = height - Data.message.winH * 2;
	Data.message.attentionWinColor = COLOR(200, 200, 100);
	Data.message.attentionWinEdgeColor = COLOR(255, 255, 255);
	Data.message.attentionTextColor = COLOR(0, 0, 0);
	Data.message.attentionTextSize = 50;
	Data.message.attentionWinW = Data.message.winW - Data.message.attentionTextSize * 6;
	Data.message.attentionWinH = 200;
	Data.message.attentionTextPos.x = Data.message.attentionWinPos.x + Data.message.textPosOfst.x - Data.message.attentionWinW / 2;
	Data.message.attentionTextPos.y = Data.message.attentionWinPos.y + Data.message.textPosOfst.y - Data.message.attentionWinH / 3;
	Data.message.yesPos.x = Data.message.attentionTextPos.x + 100;
	Data.message.yesPos.y = Data.message.attentionTextPos.y + 50;
	Data.message.noPos.x = Data.message.yesPos.x + 250,
		Data.message.noPos.y = Data.message.yesPos.y;
	Data.message.buttonColor = COLOR(200, 200, 255);
	//ローディングクラスのデータ
	Data.loading.goToTitleTime = 2;
	//プロローグクラスのデータ
	Data.message.sw = 3;
	Data.prologue.textSize = 30;
	Data.prologue.textPosOfst.x = 50;
	Data.prologue.textPosOfst.y = 50;
	Data.prologue.winH = 195;
	Data.prologue.windowPos.x = width / 2;
	Data.prologue.windowPos.y = height - Data.message.winH - Data.message.sw + 95;
	Data.prologue.winW = width - Data.message.sw * 2 - 200;
	Data.prologue.textPos.x = Data.message.windowPos.x + Data.message.textPosOfst.x - Data.message.winW / 2;
	Data.prologue.textPos.y = Data.message.windowPos.y + Data.message.textPosOfst.y - Data.message.winH / 2;
	Data.prologue.charaNameTextSize = 50;
	Data.prologue.textColor = COLOR(0, 0, 0);
	Data.prologue.winColor = COLOR(255, 255, 255);
	Data.prologue.edgeColor = COLOR(0, 0, 0);
	//タイトルクラスのデータ
	Data.title.backColor = COLOR(0, 50, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.pos.x = 0;
	Data.title.pos.y = 400;
	Data.title.textSize = 300;
	strcpy_s(Data.title.str, "TITLE");
	Data.title.buttonPos.x = width / 2;
	Data.title.buttonPos.y = height / 2 + 100;
	Data.title.buttonRadius = 50;
	Data.title.color1 = COLOR(10, 50, 190);
	Data.title.color2 = COLOR(124, 235, 234);

	//ストーリークラスのデータ
	Data.story.backColor = COLOR(0, 50, 0);
	Data.story.textColor = COLOR(0, 255, 0);
	Data.story.pos.x = 0;
	Data.story.pos.y = 400;
	Data.story.textSize = 300;
	Data.story.Flag = 0;
	Data.story.text = "スキップしますか？ ";
	Data.story.text2 = "  YES";
	Data.story.text3 = "   NO";
	Data.story.skipButtonPos.x = 820;
	Data.story.skipButtonPos.y = 550;

	//ステージクラスのデータ
	Data.stage.backColor;
	Data.stage.textColor = COLOR(0, 255, 0);
	Data.stage.pos.x = 900;
	Data.stage.pos.y = 30;

	Data.stage.textSize = 30;
	strcpy_s(Data.stage.str, "STAGE");
	//ステージクリアクラスのデータ
	Data.stageClear.backColor = COLOR(0, 50, 0);
	Data.stageClear.textColor = COLOR(0, 255, 0);
	Data.stageClear.pos.x = 0;
	Data.stageClear.pos.y = 400;
	Data.stageClear.textSize = 190;
	strcpy_s(Data.stageClear.str, "STAGE CLEAR");
	Data.stageClear.nextPos.x = 200;
	Data.stageClear.nextPos.y = height / 2;
	Data.stageClear.backToTitlePos.x = Data.stageClear.nextPos.x + 650;
	Data.stageClear.backToTitlePos.y = Data.stageClear.nextPos.y;
	Data.stageClear.nextText = "    次へ";
	Data.stageClear.backToTitleText = "タイトルに戻る";
	//ゲームオーバークラスのデータ
	Data.gameOver.backColor = COLOR(0, 50, 0);
	Data.gameOver.textColor = COLOR(0, 255, 0);
	Data.gameOver.pos.x = 0;
	Data.gameOver.pos.y = 400;
	Data.gameOver.textSize = 230;
	strcpy_s(Data.gameOver.str, "GAME OVER");
	Data.gameOver.continuePos.x = 200;
	Data.gameOver.continuePos.y = height / 2;
	Data.gameOver.backToTitlePos.x = Data.gameOver.continuePos.x + 650;
	Data.gameOver.backToTitlePos.y = Data.gameOver.continuePos.y;
	Data.gameOver.backToTitleText = "タイトルに戻る";
	Data.gameOver.continueText = "  リトライ？";

	//エンディングクラスのデータ
	Data.ending.backColor = COLOR(0, 50, 0);
	Data.ending.textColor = COLOR(0, 255, 0);
	Data.ending.pos.x = 0;
	Data.ending.pos.y = 400;
	Data.ending.textSize = 300;
	strcpy_s(Data.ending.str, "ENDING");

	//カウントダウンクラスのデータ
	Data.cd.textSize = 100;

	//メッセージクラスのテキストデータ
	Data.message.text = 0;
	//ストーリー1話のテキスト
	Data.message.text1_1 = "                ";
	Data.message.text1_2 = "                ";//////////////////////////////";26文字限界
	Data.message.text1_3 = "わっ、プレゼントくれるのかい！？ありがとう";
	Data.message.text1_4 = "でもこれ高かったんじゃない？";
	Data.message.text1_5 = "それほどでも～";
	Data.message.text1_6 = "まさか、パチンコで勝ったお金じゃないだろうね";
	Data.message.text1_7 = "……";
	Data.message.text1_8 = "…………";
	Data.message.text1_9 = "こっ";
	Data.message.text1_10 = "こ？";
	Data.message.text1_11 = "このっ、";
	Data.message.text1_12 = "バカ息子がー！！";
	Data.message.text1_13 = "";
	Data.message.text1_14 = "";
	Data.message.text1_15 = "";
	Data.message.text1_16 = "";
	Data.message.text1_17 = "";
	Data.message.text1_18 = "";
	Data.message.text1_19 = "";
	Data.message.text1_20 = "";

	//ストーリー2話のテキスト
	Data.message.text2_1 = "           ";
	Data.message.text2_2 = "はぁ、はぁ。顔こえぇんだよチクショー...！！";
	Data.message.text2_3 = "てめぇ、なめてんのか！！";
	Data.message.text2_4 = "…………。";
	Data.message.text2_5 = "チッ！お前今日交代なしな？俺もう帰るからw";
	Data.message.text2_6 = "（あれがパワハラかよ。仕事とか絶対やだわ...。）";
	Data.message.text2_7 = "やっぱニート最高、...んぇ！？";
	Data.message.text2_8 = "なんか見られてる気が...。てかこっち来てるよね...！？";
	Data.message.text2_9 = "うああああああああぁああぁあ！！！！！！！";
	Data.message.text2_10 = "くそ上司が...！死にさらせえぇぇぇ！！！";
	Data.message.text2_11 = "なんでおれぇ！？";
	Data.message.text2_12 = "";
	Data.message.text2_13 = "";
	Data.message.text2_14 = "";
	Data.message.text2_15 = "";
	Data.message.text2_16 = "";
	Data.message.text2_17 = "";
	Data.message.text2_18 = "";
	Data.message.text2_19 = "";
	Data.message.text2_20 = "";
	//ストーリー3話のテキスト
	Data.message.text3_1 = "肺が限界だよ...って、あれは！";
	Data.message.text3_2 = "　　　　　　　　　　　　";
	Data.message.text3_3 = "（俺の彼女！いつも助けてくれるからきっと...！）";
	Data.message.text3_4 = "丁度よかった、今やばいやつに追われてて...";
	Data.message.text3_5 = "あの人が新しい恋人なの？";
	Data.message.text3_6 = "は？";
	Data.message.text3_7 = "すごい楽しそうだった。";
	Data.message.text3_7_2 = "私にはお金の話しかしてくれないのに...";
	Data.message.text3_8 = "モモのこと捨てちゃうの？もう会ってくれないの？";
	Data.message.text3_9 = "え？ちょっと";
	Data.message.text3_10 = "新都が他の奴にとられる前に...";
	Data.message.text3_11 = "いやっ、あのっ";
	Data.message.text3_12 = "早く一緒に逝かないと...";
	Data.message.text3_13 = "";
	Data.message.text3_14 = "";
	Data.message.text3_15 = "";
	Data.message.text3_16 = "";
	Data.message.text3_17 = "";
	Data.message.text3_18 = "";
	Data.message.text3_19 = "";
	Data.message.text3_20 = "";
	//ストーリー4話のテキスト
	Data.message.text4_1 = "なんで誰も俺の話聞かねぇんだよ！！";
	Data.message.text4_2 = "それはお前が人の話聞かねぇからだろ";
	Data.message.text4_3 = "あぁ？なんだとてm...ヒェッ！";
	Data.message.text4_4 = "　　　　　　　　　　　";
	Data.message.text4_5 = "お前いつも母ちゃんとか彼女蔑ろにしてんだろ";
	Data.message.text4_6 = "周りのこともっと大事にしろよ";
	Data.message.text4_7 = "は？んなことしてねぇよ！だいたいなぁ...";
	Data.message.text4_8 = "（...こいつ全然反省してねえ感じだよな）";
	Data.message.text4_9 = "っていうかなに人ん家のことに...";
	Data.message.text4_10 = "天誅ぅうぅぅ！！";
	Data.message.text4_11 = "";
	Data.message.text4_12 = "";
	Data.message.text4_13 = "";
	Data.message.text4_14 = "";
	Data.message.text4_15 = "";
	Data.message.text4_16 = "";
	Data.message.text4_17 = "";
	Data.message.text4_18 = "";
	Data.message.text4_19 = "";
	Data.message.text4_20 = "";
	//ストーリー5話のテキスト
	Data.message.text5_1 = "　　　　　　　　　";
	Data.message.text5_2 = "はぁ、結局家に帰ってきちまった...";
	Data.message.text5_3 = "ただいま～";
	Data.message.text5_4 = "（ていうか、流石に母ちゃんの機嫌治ってるよな？）";
	Data.message.text5_5 = "…………";
	Data.message.text5_6 = "うぅ、私のせいだわ";
	Data.message.text5_7 = "え？";
	Data.message.text5_8 = "私だけでなくて人様にまで迷惑を...";
	Data.message.text5_9 = "パチンコに競馬にやりたい放題だし...";
	Data.message.text5_10 = "こんなんじゃ、あの人に合わせる顔がないわ！";
	Data.message.text5_11 = "えっ、待ってよかぁちゃん...！！！";
	Data.message.text5_12 = "";
	Data.message.text5_13 = "";
	Data.message.text5_14 = "";
	Data.message.text5_15 = "";
	Data.message.text5_16 = "";
	Data.message.text5_17 = "";
	Data.message.text5_18 = "";
	Data.message.text5_19 = "";
	Data.message.text5_20 = "";
	//ストーリー最終話のテキスト
	Data.message.textLast_1 = "え、かぁちゃんコンビニに入ってったんだけど...";
	Data.message.textLast_2 = "ありがとうございました～";
	Data.message.textLast_3 = "新都、帰るよ";
	Data.message.textLast_4 = "ふぁっ？";
	Data.message.textLast_5 = "もう夜も遅いからね、ほら、これ持って";
	Data.message.textLast_6 = "え、も、もう見限ったんじゃ...";
	Data.message.textLast_7 = "何のために酒を買ったと思ってるんだい";
	Data.message.textLast_8 = "腹割って朝まで飲み明かすよ";
	Data.message.textLast_9 = "...母ちゃん大好き！！！！！！";
	Data.message.textLast_10 = "うるさいよ！！！！！！";
	Data.message.textLast_11 = "　　　　　　　　　　　";
	Data.message.textLast_12 = "";
	Data.message.textLast_13 = "";
	Data.message.textLast_14 = "";
	Data.message.textLast_15 = "";
	Data.message.textLast_16 = "";
	Data.message.textLast_17 = "";
	Data.message.textLast_18 = "";
	Data.message.textLast_19 = "";
	Data.message.textLast_20 = "";
	//キャラ名
	Data.message.space = "                ";
	//ステートを次に進めるための空のテキスト
	Data.message.text_Last = "             ";
	//プレイヤークラスのデータ
	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 1;
	Data.playerChara.groupId = 0;//味方グループは0
	Data.playerChara.offsetLeft = 20.0f * 2;
	Data.playerChara.offsetTop = 0.2f * 2;
	Data.playerChara.offsetRight = 60.0f * 2;
	Data.playerChara.offsetBottom = 60.0f * 2;
	Data.playerChara.knockBackVx = 100;
	Data.playerChara.knockBackVy = 100;
	Data.playerChara.maxStamina = 100;
	Data.playerChara.stamina = 0;
	Data.player.jumpFlag = 0;
	Data.player.initVecUp = -16.0f * 1.1f;
	Data.player.initVecDown = 3.0f * 1.1f;
	Data.player.gravity = 48;
	Data.playerChara.damageTime = 0;
	Data.playerChara.damageInterval = 5 * 0.016f * 2;
	Data.player.damageColor = COLOR(255, 0, 0, 25);
	Data.player.normalColor = COLOR(255, 255, 255);
	Data.player.bulletOffsetX = 20.0f;
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;

	Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
	Data.playerBulletChara.groupId = 0;//味方グループは0 
	Data.playerBulletChara.hp = 1;
	Data.playerBulletChara.speed = 15.0f * 60;
	Data.playerBulletChara.offsetLeft = 10.0f * 2;
	Data.playerBulletChara.offsetTop = 12.0f * 2;
	Data.playerBulletChara.offsetRight = 60.0f * 2;
	Data.playerBulletChara.offsetBottom = 30.0f * 2;


	//エネミークラスのデータ
	Data.enemyChara.charaId = MAP::ENEMY_ID;
	Data.enemyChara.hp = 1;
	Data.enemyChara.groupId = 1;//味方グループは0
	Data.enemyChara.offsetLeft = 10.0f * 2;
	Data.enemyChara.offsetTop = 1.0f * 2;
	Data.enemyChara.offsetRight = 60.0f * 2;
	Data.enemyChara.offsetBottom = 55.0f * 2;
	Data.enemyChara.maxStamina = 150;
	Data.enemyChara.stamina = 0;
	Data.enemyChara.damageTime = 0;
	Data.enemyChara.damageInterval = 5 * 0.016f * 2 * 2;
	Data.enemyChara.knockBackVx = -100;
	Data.enemyChara.knockBackVy = 100;
	Data.enemy.jumpFlag = 0;
	Data.enemy.initVecUp = -16.0f * 1.1f;
	Data.enemy.initVecDown = 3.0f * 1.1f;
	Data.enemy.charaDamage = 0;
	Data.enemy.gravity = 48;
	Data.enemy.bulletOffsetX = 20.0f * 2;
	Data.enemy.elapsedTime = 0;
	Data.enemy.interval = 0.016f;
	Data.enemy.triggerCnt = 100;
	Data.enemy.triggerInterval = 400;
	Data.enemy.trigger1st = 220;
	Data.enemy.trigger2nd = 270;
	Data.enemy.trigger3rd = 380;
	Data.enemy.trigger4th = 400;
	Data.enemy.damageColor = COLOR(255, 0, 0, 25);
	Data.enemy.normalColor = COLOR(255, 255, 255);
	Data.enemy.bulletCharaId = MAP::ENEMY_BULLET_ID;

	Data.onisanChara.charaId = MAP::ONISAN_ID;
	Data.onisanChara.hp = 1;
	Data.onisanChara.groupId = 1;//味方グループは0
	Data.onisanChara.offsetLeft = 10.0f * 2;
	Data.onisanChara.offsetTop = 1.0f * 2;
	Data.onisanChara.offsetRight = 60.0f * 2;
	Data.onisanChara.offsetBottom = 55.0f * 2;
	Data.onisanChara.maxStamina = 200;
	Data.onisanChara.stamina = 0;
	Data.onisanChara.damageTime = 0;
	Data.onisanChara.damageInterval = 5 * 0.016f * 2 * 2;
	Data.onisanChara.knockBackVx = -100;
	Data.onisanChara.knockBackVy = 100;
	Data.onisan.jumpFlag = 0;
	Data.onisan.initVecUp = -16.0f * 1.1f;
	Data.onisan.initVecDown = 3.0f * 1.1f;
	Data.onisan.charaDamage = 0;
	Data.onisan.gravity = 48;
	Data.onisan.bulletOffsetX = 20.0f * 2;
	Data.onisan.elapsedTime = 0;
	Data.onisan.interval = 0.016f;
	Data.onisan.triggerCnt = 100;
	Data.onisan.triggerInterval = 400;
	Data.onisan.trigger1st = 220;
	Data.onisan.trigger2nd = 270;
	Data.onisan.trigger3rd = 380;
	Data.onisan.trigger4th = 400;
	Data.onisan.damageColor = COLOR(255, 0, 0, 25);
	Data.onisan.normalColor = COLOR(255, 255, 255);
	Data.onisan.bulletCharaId = MAP::ENEMY_BULLET_ID;
	//チンピラクラスのデータ
	Data.chinpiraChara.charaId = MAP::CHINPIRA_ID;
	Data.chinpiraChara.hp = 1;
	Data.chinpiraChara.groupId = 1;//味方グループは0
	Data.chinpiraChara.offsetLeft = 10.0f * 2;
	Data.chinpiraChara.offsetTop = 1.0f * 2;
	Data.chinpiraChara.offsetRight = 60.0f * 2;
	Data.chinpiraChara.offsetBottom = 55.0f * 2;
	Data.chinpiraChara.maxStamina = 250;
	Data.chinpiraChara.stamina = 0;
	Data.chinpiraChara.damageTime = 0;
	Data.chinpiraChara.damageInterval = 5 * 0.016f * 2 * 2;
	Data.chinpiraChara.knockBackVx = -100;
	Data.chinpiraChara.knockBackVy = 100;
	Data.chinpira.jumpFlag = 0;
	Data.chinpira.initVecUp = -16.0f * 1.1f;
	Data.chinpira.initVecDown = 3.0f * 1.1f;
	Data.chinpira.charaDamage = 0;
	Data.chinpira.gravity = 48;
	Data.chinpira.bulletOffsetX = 20.0f * 2;
	Data.chinpira.elapsedTime = 0;
	Data.chinpira.interval = 0.016f;
	Data.chinpira.triggerCnt = 100;
	Data.chinpira.triggerInterval = 400;
	Data.chinpira.trigger1st = 220;
	Data.chinpira.trigger2nd = 270;
	Data.chinpira.trigger3rd = 380;
	Data.chinpira.trigger4th = 400;
	Data.chinpira.damageColor = COLOR(255, 0, 0, 25);
	Data.chinpira.normalColor = COLOR(255, 255, 255);
	Data.chinpira.bulletCharaId = MAP::ENEMY_BULLET_ID;

	Data.menheraChara.charaId = MAP::MENHERA_ID;
	Data.menheraChara.hp = 1;
	Data.menheraChara.groupId = 1;//味方グループは0
	Data.menheraChara.offsetLeft = 10.0f * 2;
	Data.menheraChara.offsetTop = 1.0f * 2;
	Data.menheraChara.offsetRight = 60.0f * 2;
	Data.menheraChara.offsetBottom = 55.0f * 2;
	Data.menheraChara.maxStamina = 200;
	Data.menheraChara.stamina = 0;
	Data.menheraChara.damageTime = 0;
	Data.menheraChara.damageInterval = 5 * 0.016f * 2 * 2;
	Data.menheraChara.knockBackVx = -100;
	Data.menheraChara.knockBackVy = 100;
	Data.menhera.jumpFlag = 0;
	Data.menhera.initVecUp = -16.0f * 1.1f;
	Data.menhera.initVecDown = 3.0f * 1.1f;
	Data.menhera.charaDamage = 0;
	Data.menhera.gravity = 48;
	Data.menhera.bulletOffsetX = 20.0f * 2;
	Data.menhera.elapsedTime = 0;
	Data.menhera.interval = 0.016f;
	Data.menhera.triggerCnt = 100;
	Data.menhera.triggerInterval = 400;
	Data.menhera.trigger1st = 220;
	Data.menhera.trigger2nd = 270;
	Data.menhera.trigger3rd = 380;
	Data.menhera.trigger4th = 400;
	Data.menhera.damageColor = COLOR(255, 0, 0, 25);
	Data.menhera.normalColor = COLOR(255, 255, 255);
	Data.menhera.bulletCharaId = MAP::ENEMY_BULLET_ID;

	Data.enemyBulletChara.charaId = MAP::ENEMY_BULLET_ID;
	Data.enemyBulletChara.groupId = 1;//敵グループは1
	Data.enemyBulletChara.hp = 1;
	Data.enemyBulletChara.speed = 7.5f * 60;
	Data.enemyBulletChara.offsetLeft = 10.0f * 2;
	Data.enemyBulletChara.offsetTop = 12.0f * 2;
	Data.enemyBulletChara.offsetRight = 60.0f * 2;
	Data.enemyBulletChara.offsetBottom = 60.0f * 2;
	Data.enemyBullet.rightAnimId = 0;
	Data.enemyBullet.leftAnimId = 1;
	Data.enemyBullet.damageInterval = 5 * 0.016f;
	Data.enemyBullet.initVecX = 1;
	Data.enemyBullet.initVecY = 0;
	Data.enemyBullet.gravity = 0.8f * 60;
	Data.enemyBullet.alphaLowVal = 25;
	Data.enemyBullet.damageColor = COLOR(255, 0, 0);


	Data.catChara.charaId = MAP::CAT_ID;
	Data.catChara.hp = 1;
	Data.catChara.groupId = 2;//敵グループは1
	Data.catChara.offsetLeft = 10.0f * 2;
	Data.catChara.offsetTop = -40.0f * 2;
	Data.catChara.offsetRight = 70.0f * 2;
	Data.catChara.offsetBottom = 5.0f * 2;
	Data.catChara.speed = -3.4f * 60;

	Data.cokeChara.charaId = MAP::COKE_ID;
	Data.cokeChara.hp = 1;
	Data.cokeChara.groupId = 2;
	Data.cokeChara.offsetLeft = 20.0f * 2;
	Data.cokeChara.offsetTop = 20.0f * 2;
	Data.cokeChara.offsetRight = 50.0f * 2;
	Data.cokeChara.offsetBottom = 70.0f * 2;

	Data.tipsChara.charaId = MAP::TIPS_ID;
	Data.tipsChara.hp = 1;
	Data.tipsChara.groupId = 2;
	Data.tipsChara.offsetLeft = 20.0f * 2;
	Data.tipsChara.offsetTop = 20.0f * 2;
	Data.tipsChara.offsetRight = 70.0f * 2;
	Data.tipsChara.offsetBottom = 70.0f * 2;

	Data.ramenChara.charaId = MAP::RAMEN_ID;
	Data.ramenChara.hp = 1;
	Data.ramenChara.groupId = 2;
	Data.ramenChara.offsetLeft = 20.0f * 2 - 5;
	Data.ramenChara.offsetTop = 20.0f * 2;
	Data.ramenChara.offsetRight = 110.0f * 2 - 5;
	Data.ramenChara.offsetBottom = 70.0f * 2;

	Data.bearChara.charaId = MAP::BEAR_ID;
	Data.bearChara.hp = 1;
	Data.bearChara.groupId = 2;
	Data.bearChara.offsetLeft = 20.0f * 2;
	Data.bearChara.offsetTop = 20.0f * 2;
	Data.bearChara.offsetRight = 70.0f * 2;
	Data.bearChara.offsetBottom = 70.0f * 2;



	Data.holeChara.charaId = MAP::MANHOLE_ID;
	Data.holeChara.groupId = 1;//敵グループは1
	Data.holeChara.hp = 1;
	Data.holeChara.offsetLeft = 20.0f * 2;
	Data.holeChara.offsetTop = 0.0f * 2;
	Data.holeChara.offsetRight = 70.0f * 2;
	Data.holeChara.offsetBottom = 80.0f * 2;

	Data.ebifuraiChara.charaId = MAP::EBIFURAI_ID;
	Data.ebifuraiChara.hp = 1;
	Data.ebifuraiChara.speed = -2.5f * 60;
	Data.ebifuraiChara.groupId = 2;
	Data.ebifuraiChara.offsetLeft = 20.0f * 2;
	Data.ebifuraiChara.offsetTop = 20.0f * 2;
	Data.ebifuraiChara.offsetRight = 50.0f * 2;
	Data.ebifuraiChara.offsetBottom = 70.0f * 2;
	Data.ebifurai.jumpFlag = 0;
	Data.ebifurai.initVecUp = -16.0f;
	Data.ebifurai.initVecDown = 3.0f;
	Data.ebifurai.gravity = 48;

	Data.rymanChara.charaId = MAP::RYMAN_ID;
	Data.rymanChara.hp = 1;
	Data.rymanChara.speed = -4.0f * 60;
	Data.rymanChara.groupId = 2;
	Data.rymanChara.offsetLeft = 20.0f * 2 - 5;
	Data.rymanChara.offsetTop = 20.0f * 2;
	Data.rymanChara.offsetRight = 50.0f * 2 - 10 - 5;
	Data.rymanChara.offsetBottom = 70.0f * 2;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numEnemies = 1;
	Data.charaMng.numOnisan = 1;
	Data.charaMng.numMenhera = 1;

	Data.charaMng.numChinpira = 1;
	Data.charaMng.numCats = 10;
	Data.charaMng.numEnemyBullets = 5;
	Data.charaMng.numHoles = 3;
	Data.charaMng.numCokes = 7;
	Data.charaMng.numTips = 4;
	Data.charaMng.numBears = 3;
	Data.charaMng.numRamens = 5;
	Data.charaMng.numEbifurais = 6;
	Data.charaMng.numRymans = 5;
	Data.charaMng.numPlayerBullets = 5;


	//フェードクラスのデータ
	Data.fade.color = COLOR(60, 60, 60);
	Data.fade.speed = 250 * 2;
	//ボタンクラスのデータ
	Data.button.radius = 5;
	//マップクラスのデータ
	Data.map.fileName = 0;
	Data.map.fileName1 = "assets\\map1.txt";
	Data.map.fileName2 = "assets\\map2.txt";
	Data.map.fileName3 = "assets\\map3.txt";
	Data.map.fileName4 = "assets\\map4.txt";
	Data.map.fileName5 = "assets\\map5.txt";

	Data.map.chipSize = 100;
	Data.map.scale = 1;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;
}
void CONTAINER::LoadGraphics() {
	Data.title.image = loadImage("assets\\startImg.png");
	Data.title.image2 = loadImage("assets\\startButton.png");
	Data.title.helpImage = loadImage("assets\\ex_01.png");

	Data.story.backImg[0] = loadImage("assets\\ストーリー背景\\ストーリー背景\\home.png");
	Data.story.backImg[1] = loadImage("assets\\ストーリー背景\\ストーリー背景\\kouji.png");
	Data.story.backImg[2] = loadImage("assets\\ストーリー背景\\ストーリー背景\\roji_01.png");
	Data.story.backImg[3] = loadImage("assets\\ストーリー背景\\ストーリー背景\\roji_02.png");
	Data.story.backImg[4] = loadImage("assets\\ストーリー背景\\ストーリー背景\\store.png");

	Data.story.skipImg = loadImage("assets\\skip.png");
	Data.story.skipImg2 = loadImage("assets\\skip.png");
	Data.message.yesImg1 = loadImage("assets\\ok.png");
	Data.message.yesImg2 = loadImage("assets\\ok.png");
	Data.message.noImg1 = loadImage("assets\\no.png");
	Data.message.noImg2 = loadImage("assets\\no.png");


	Data.stage.backImg = loadImage("assets\\back.png");

	Data.stageClear.img = loadImage("assets\\リザルト\\リザルト\\sc.png");

	Data.gameOver.retryImg = loadImage("assets\\リザルト\\リザルト\\retry.png");
	Data.gameOver.gotoTitleImg = loadImage("assets\\リザルト\\リザルト\\title.png");
	Data.gameOver.retryImg2 = loadImage("assets\\リザルト\\リザルト\\retry.png");
	Data.gameOver.gotoTitleImg2 = loadImage("assets\\リザルト\\リザルト\\title.png");

	Data.stageClear.nextButtonImg = loadImage("assets\\リザルト\\リザルト\\next.png");
	Data.stageClear.gotoTitleButtonImg = loadImage("assets\\リザルト\\リザルト\\title.png");
	Data.stageClear.nextButtonImg2 = loadImage("assets\\リザルト\\リザルト\\next.png");
	Data.stageClear.gotoTitleButtonImg2 = loadImage("assets\\リザルト\\リザルト\\title.png");
	Data.gameOver.img = loadImage("assets\\リザルト\\リザルト\\go.png");

	Data.map.blockImg = loadImage("assets\\block.png");
	Data.map.poleImg = loadImage("assets\\item\\item\\障害物\\hole_2.png");

	Data.cd.image = Data.stage.backImg;
	Data.enemyBulletChara.img1 = loadImage("assets\\item\\item\\敵アイテム\\okan_book.png");
	Data.enemyBulletChara.img2 = loadImage("assets\\item\\item\\敵アイテム\\light.png");
	Data.enemyBulletChara.img3 = loadImage("assets\\item\\item\\敵アイテム\\candy.png");
	Data.enemyBulletChara.img4 = loadImage("assets\\item\\item\\敵アイテム\\cut.png");

	Data.holeChara.img = loadImage("assets\\item\\item\\障害物\\skull.png");
	Data.cokeChara.img = loadImage("assets\\item\\item\\回復\\cola.png");
	Data.tipsChara.img = loadImage("assets\\item\\item\\回復\\potato.png");
	Data.ramenChara.img = loadImage("assets\\item\\item\\回復\\men.png");
	Data.bearChara.img = loadImage("assets\\item\\item\\回復\\Beer.png");

	Data.catChara.img = loadImage("assets\\item\\item\\障害物\\cat.png");


	Data.ebifuraiChara.img = loadImage("assets\\item\\item\\障害物\\fry.png");
	Data.rymanChara.img = loadImage("assets\\item\\item\\障害物\\human.png");

	Data.ending.img[0] = loadImage("assets\\エンドロール\\end_01.png");
	Data.ending.img[1] = loadImage("assets\\エンドロール\\end_02.png");
	Data.ending.img[2] = loadImage("assets\\エンドロール\\end_03.png");
	Data.ending.img[3] = loadImage("assets\\エンドロール\\end_04.png");
	Data.ending.img[4] = loadImage("assets\\エンドロール\\end_05.png");

	//ANIMS 複数のアニメーションセット
	Data.loading.anim = new ANIM("assets\\loading\\load");
	Data.loading.anim->noLoop();

	Data.loading.animData.interval = 0.1f;

	Data.playerChara.anims = new ANIMS("assets\\新都");
	Data.playerChara.animData.interval = 0.1f;

	Data.enemyChara.anims = new ANIMS("assets\\おかん");
	Data.enemyChara.animData.interval = 0.1f;

	Data.onisanChara.anims = new ANIMS("assets\\おにいさん");
	Data.onisanChara.animData.interval = 0.1f;

	Data.chinpiraChara.anims = new ANIMS("assets\\チンピラ");
	Data.chinpiraChara.animData.interval = 0.1f;

	Data.menheraChara.anims = new ANIMS("assets\\メンヘラ");
	Data.menheraChara.animData.interval = 0.1f;

	Data.playerBulletChara.img = loadImage("assets\\word.png");

	Data.message.okanDefImg = loadImage("assets\\sChara\\okan\\11_df.png");
	Data.message.okanAngImg = loadImage("assets\\sChara\\okan\\12_ag.png");
	Data.message.okanHpImg = loadImage("assets\\sChara\\okan\\13_hp.png");
	Data.message.okanSpImg = loadImage("assets\\sChara\\okan\\14_sp.png");
	Data.message.okanDlImg = loadImage("assets\\sChara\\okan\\15_dl.png");

	Data.message.neetDefImg = loadImage("assets\\sChara\\neet\\11_df.png");
	Data.message.neetAngImg = loadImage("assets\\sChara\\neet\\12_ag.png");
	Data.message.neetHpImg = loadImage("assets\\sChara\\neet\\13_hp.png");
	Data.message.neetSpImg = loadImage("assets\\sChara\\neet\\14_sp.png");
	Data.message.neetDlImg = loadImage("assets\\sChara\\neet\\15_dl.png");
	Data.message.neetPnImg = loadImage("assets\\sChara\\neet\\16_pn.png");


	Data.message.onisanDefImg = loadImage("assets\\sChara\\onisan\\11_df.png");
	Data.message.onisanAngImg = loadImage("assets\\sChara\\onisan\\12_ag.png");
	Data.message.onisanHpImg = loadImage("assets\\sChara\\onisan\\13_hp.png");
	Data.message.onisanSpImg = loadImage("assets\\sChara\\onisan\\14_sp.png");
	Data.message.onisanDlImg = loadImage("assets\\sChara\\onisan\\15_dl.png");


	Data.message.menheraDefImg = loadImage("assets\\sChara\\menhera\\11_df.png");
	Data.message.menheraAngImg = loadImage("assets\\sChara\\menhera\\12_ag.png");
	Data.message.menheraHpImg = loadImage("assets\\sChara\\menhera\\13_hp.png");
	Data.message.menheraSpImg = loadImage("assets\\sChara\\menhera\\14_sp.png");
	Data.message.menheraDlImg = loadImage("assets\\sChara\\menhera\\15_dl.png");


	Data.message.chinpiraDefImg = loadImage("assets\\sChara\\chinpira\\11_df.png");
	Data.message.chinpiraAngImg = loadImage("assets\\sChara\\chinpira\\12_ag.png");
	Data.message.chinpiraHpImg = loadImage("assets\\sChara\\chinpira\\13_hp.png");
	Data.message.chinpiraSpImg = loadImage("assets\\sChara\\chinpira\\14_sp.png");
	Data.message.chinpiraDlImg = loadImage("assets\\sChara\\chinpira\\15_dl.png");




}
