var realData = "";

const getData = async () => {
  const api =
    "https://api.github.com/repos/geeks-hub-nith/C-Plus-Plus/contributors";
  try {
    let data = await fetch(api);
    let realData1 = await data.json();
    let realData = realData1;
    console.log(realData);
  } catch (error) {
    console.log(error);
  }
  return realData;
};
export default realData;
