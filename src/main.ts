import * as express from "express";
import * as bodyParser from "body-parser";

class Main {
    public app: express.Application;
    constructor() {
        this.app = express();
        this.config();
    }
    private config(): void {
        this.app.use(bodyParser.json());
        this.app.use(bodyParser.urlencoded({ extended : false }));
    }
}

class Article {
    
}

const main = new Main();
main.app.listen(3000, () => { 
    console.log("Express server is listening");
});