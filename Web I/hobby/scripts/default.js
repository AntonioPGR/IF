// --- Set the Page Title ---
document.title = "Astronomia";


// --- Set the Language ---
document.documentElement.lang = "pt-BR";


// --- Add Meta Tags ---
const metaCharset = document.createElement("meta");
metaCharset.setAttribute("charset", "UTF-8");
document.head.appendChild(metaCharset);

const metaViewport = document.createElement("meta");
metaViewport.name = "viewport";
metaViewport.content = "width=device-width, initial-scale=1.0";
document.head.appendChild(metaViewport);


// --- Add a Favicon ---
link = document.createElement('link');
link.rel = 'icon';
document.head.appendChild(link);
link.type = 'image/png';
link.href = 'images/favicon.png';


// --- Add a Stylesheet ---
const default_css = document.createElement('link');
default_css.rel = 'stylesheet';
default_css.type = 'text/css';
default_css.href = "css/default.css";
document.head.appendChild(default_css);

const header_css = document.createElement('link');
header_css.rel = 'stylesheet';
header_css.type = 'text/css';
header_css.href = "css/header.css";
document.head.appendChild(header_css);

const footer_css = document.createElement('link');
footer_css.rel = 'stylesheet';
footer_css.type = 'text/css';
footer_css.href = "css/footer.css";
document.head.appendChild(footer_css);

// --- Add a Header ---
document.addEventListener('DOMContentLoaded', async () => {
  const response = await fetch("components/header.html");
  const htmlText = await response.text();
  document.body.insertAdjacentHTML('afterbegin', htmlText);
});


// --- Add a Footer ---
document.addEventListener('DOMContentLoaded', async () => {
  const response = await fetch("components/footer.html");
  const htmlText = await response.text();
  document.body.insertAdjacentHTML('beforeend', htmlText);
});