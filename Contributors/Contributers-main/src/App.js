import "./styles.css";
import "bootstrap/dist/css/bootstrap.min.css";
import Grid from "./Grid";
import Navbar from "./Navbar";
import Footer from "./Footer";

export default function App() {
  return (
    <div className="App">
      <Navbar />
      <br />
      <Grid />

      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>
      <Footer />
    </div>
  );
}
