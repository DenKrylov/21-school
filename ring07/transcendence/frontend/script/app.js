new Vue({
	el: '.app',
	data: {
		login: false, 
		mainPage: true,
		signPage: false,
		chatPage: false,
		gamePage: false,
		tmpDialog: '',
		tmpMessage: '',
		userMenu: false,
		scoreOne: 3,
		scoreTwo: 7,
		activeChat: 'Transcendence', //полюбому должен быть активный чат
		numberOfMessages: 0,
		user: 'Monie', // имя пользователя залогиневшего
		enemy: 'Esnowbal',
		bestGamer: 'Monie', //лучший игрок сохраняется в бд
		theme: true, //цвет темы. Должна сохраняться с бд
		chats: [
			{
				name: 'Transcendence',
				message: 'Last message',
				index: 4,
				dialog: [
					{
						user: 'Esnowbal',
						text: 'Привет всем!'
					},
					{
						user: 'Monie',
						text: 'Привет!'
					},
					{
						user: 'Ngonzo',
						text: 'Приветики!'
					},
					{
						user: 'Sultan',
						text: 'Я вас опять скипну с чата!'
					},
				]
			},
			{
				name: 'Ngonzo',
				message: 'Last message',
				index: 4,
				dialog: [
					{
						user: 'Ngonzo',
						text: 'Привет!'
					},
					{
						user: 'Monie',
						text: 'Привет!'
					},
					{
						user: 'Ngonzo',
						text: 'Когда в школу?!'
					},
					{
						user: 'Monie',
						text: 'Скоро приду!'
					},
				]
			},
			{
				name: 'Esnowbal',
				message: 'Last message',
				index: 3,
				dialog: [
					{
						user: 'Esnowbal',
						text: 'Привет!'
					},
					{
						user: 'Monie',
						text: 'Привет!'
					},
					{
						user: 'Esnowbal',
						text: 'Все надаел ты мне уже!'
					}
				]
			},
			{
				name: 'Gwynthon',
				message: 'Last message',
				index: 2,
				dialog: [
					{
						user: 'Monie',
						text: 'Привет!'
					},
					{
						user: 'Gwynton',
						text: 'Привет!'
					}
				]
			},
			{
				name: 'Hrewa',
				message: 'Last message',
				index: 2,
				dialog: [
					{
						user: 'Monie',
						text: 'Привет! Опять с девченками тусишь?!'
					},
					{
						user: 'Hrewa',
						text: 'Привет! Нее!'
					}
				]
			},
		],

	},
	methods: {
		showSign: function() {
			signPage = true;
		},
		checkLogin: function() {
			this.signPage = false;
			this.login = true;
		},
		showHome: function() {
			this.mainPage = true;
			this.signPage = false;
			this.chatPage = false;
			this.gamePage = false;
		},
		showSign: function() {
			this.mainPage = true;
			this.signPage = true;
			this.chatPage = false;
			this.gamePage = false;
		},
		showChat: function() {
			this.mainPage = false;
			this.signPage = false;
			this.chatPage = true;
			this.gamePage = false;
		},
		showGame: function() {
			this.mainPage = false;
			this.signPage = false;
			this.chatPage = false;
			this.gamePage = true;
		},
		logout: function() {
			this.mainPage = true;
			this.signPage = false;
			this.chatPage = false;
			this.gamePage = false;
			this.login = false;
		},
		changeTheme: function() {
			if(this.theme) {
				this.theme = false;
			} else {
				this.theme = true;
			}
		},
		iconTheme: function() {
			if(this.theme) {
				return("icon/brightness_6_white_24dp.svg");
			} else {
				return("icon/brightness_6_black_24dp.svg");
			}
		},
		isActiveMain: function() {
			if(this.mainPage == true) {
				return("header_li_active");
			}
		},
		isActiveChat: function() {
			if(this.chatPage == true) {
				return("header_li_active");
			}
		},
		isActiveGame: function() {
			if(this.gamePage == true) {
				return("header_li_active");
			}
		},
		pageIntra: function() {
			return("https://profile.intra.42.fr/users/ + this.user"); // ERROR
		},
		setActiveChat: function(chat) {
			this.activeChat = chat.name;
			this.numberOfMessages = chat.index;
		},
		getActiveChat: function(chat) {
			if(this.activeChat == chat) {
				return("chat_active");
			}
		},
		getClassDialog: function(user) {
			if(user == this.user) {
				return("dialog_my");
			} else {
				return("dialog_other");
			}
		},
		lastMessage: function() {
			for(text in this.chats) {
				console.log(text);
			}
		},
		getDialog: function(chats) {
			for(i = 0; i < chats.length; i++) {
				if(chats[i].name == this.activeChat) {
					this.tmpDialog = i;
					return(chats[i].dialog);
				}
			}
		},
		sendMessage: function() {
			let newMessage = {
				user: this.user,
				text: this.tmpMessage,
			};
			if(this.tmpMessage != '') {
				this.chats[this.tmpDialog].dialog.push(newMessage);

			}
			this.tmpMessage = '';
		},
		getProfileUser: function() {
			return('https://profile.intra.42.fr/users/' + this.user.toLowerCase());
		},
		changeUserMenu: function() {
			if(this.userMenu) {
				this.userMenu = false;
			} else {
				this.userMenu = true;
			}
		},
		changeUserMenuFalse: function() {
			if(this.userMenu) {
				this.userMenu = false;
			}
		},
		changeColorUser: function() {
			if(this.userMenu) {
				return('header_use__active');
			}
		},
		headeMid: function() {
			if(this.gamePage) {
				return('header_midCenter');
			}
		},
		vTeme: function(str) {
			if(this.theme) {
				console.log(str + '_dark');
				return(str + '_dark');
			} else {
				return(str + '_light')
			}
		} 
	}
})