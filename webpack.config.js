const path = require('path');
const outputDir = path.join(__dirname, "example/");

const isProd = process.env.NODE_ENV === 'production';

module: {
    loaders: [{
        test: /.jsx?$/,
        loader: 'babel-loader',
        exclude: /node_modules/
    }, {
        test: /\.css$/,
        loader: "style-loader!css-loader"
    }, {
        test: /\.(jpe?g|png|gif|woff|woff2|eot|ttf|svg)(\?[a-z0-9=.]+)?$/,
        loader: 'url-loader?limit=100000' }]
};

module.exports = {
    entry: './example/src/Index.bs.js',
    mode: isProd ? 'production' : 'development',
    output: {
        path: outputDir,
        publicPath: outputDir,
        filename: 'index.js',
    },
};
